package shasta

import (
	"fmt"
)

/*
func (b *planBuilder) buildSelect(sel *ast.SelectStmt) LogicalPlan {
	var (
		p        LogicalPlan
		aggFuncs []*ast.AggregateFuncExpr
		totalMap map[*ast.AggregateFuncExpr]int
		gbyCols  []expression.Expression
	)
	p = b.buildResultSetNode(sel.From.TableRefs)
	originalFields := sel.Fields.Fields
	p, gbyCols = b.resolveGbyExprs(p, sel.GroupBy, sel.Fields.Fields)
	p = b.buildSelection(p, sel.Where, nil)
	aggFuncs, totalMap = b.extractAggFuncs(sel.Fields.Fields)
	var aggIndexMap map[int]int
	p, aggIndexMap = b.buildAggregation(p, aggFuncs, gbyCols)
	for k, v := range totalMap {
		totalMap[k] = aggIndexMap[v]
	}
	var oldLen int
	p, oldLen = b.buildProjection(p, sel.Fields.Fields, totalMap)
	sel.Fields.Fields = originalFields
	if oldLen != p.Schema().Len() {
		proj := LogicalProjection{Exprs: expression.Column2Exprs(p.Schema().Columns[:oldLen])}.init(b.ctx)
		proj.SetChildren(p)
		schema := expression.NewSchema(p.Schema().Clone().Columns[:oldLen]...)
		for _, col := range schema.Columns {
			col.FromID = proj.ID()
		}
		proj.SetSchema(schema)
		return proj
	}

	return p
}
*/

/*
func (b *planBuilder) resolveGbyExprs(p LogicalPlan, gby *ast.GroupByClause, fields []*ast.SelectField) (LogicalPlan, []Expression) {
	//b.curClause = groupByClause
	exprs := make([]Expression, 0, len(gby.Items))
	resolver := &gbyResolver{
		fields: fields,
		schema: p.Schema(),
	}
	for _, item := range gby.Items {
		resolver.inExpr = false
		retExpr, _ := item.Expr.Accept(resolver)
		if resolver.err != nil {
			b.err = errors.Trace(resolver.err)
			return nil, nil
		}
		item.Expr = retExpr.(ast.ExprNode)
		expr, np, err := b.rewrite(item.Expr, p, nil, true)
		if err != nil {
			b.err = errors.Trace(err)
			return nil, nil
		}
		exprs = append(exprs, expr)
		p = np
	}
	return p, exprs
}
*/

func (b *planBuilder) buildAggregation(p LogicalPlan, aggFuncList []*ast.AggregateFuncExpr, gbyItems []expression.Expression) (LogicalPlan, map[int]int) {
	plan4Agg := LogicalAggregation{AggFuncs: make([]*aggregation.AggFuncDesc, 0, len(aggFuncList))}.init(b.ctx)
	schema4Agg := expression.NewSchema(make([]*expression.Column, 0, len(aggFuncList)+p.Schema().Len())...)
	// aggIdxMap maps the old index to new index after applying common aggregation functions elimination.
	aggIndexMap := make(map[int]int)

	for i, aggFunc := range aggFuncList {
		newArgList := make([]expression.Expression, 0, len(aggFunc.Args))
		for _, arg := range aggFunc.Args {
			newArg, np, err := b.rewrite(arg, p, nil, true)
			p = np
			newArgList = append(newArgList, newArg)
		}
		newFunc := aggregation.NewAggFuncDesc(b.ctx, aggFunc.F, newArgList, aggFunc.Distinct)
		combined := false
		for j, oldFunc := range plan4Agg.AggFuncs {
			if oldFunc.Equal(b.ctx, newFunc) {
				aggIndexMap[i] = j
				combined = true
				break
			}
		}
		if !combined {
			position := len(plan4Agg.AggFuncs)
			aggIndexMap[i] = position
			plan4Agg.AggFuncs = append(plan4Agg.AggFuncs, newFunc)
			schema4Agg.Append(&expression.Column{
				FromID:      plan4Agg.id,
				ColName:     model.NewCIStr(fmt.Sprintf("%d_col_%d", plan4Agg.id, position)),
				Position:    position,
				IsAggOrSubq: true,
				RetType:     newFunc.RetTp})
		}
	}
	for _, col := range p.Schema().Columns {
		newFunc := aggregation.NewAggFuncDesc(b.ctx, ast.AggFuncFirstRow, []expression.Expression{col.Clone()}, false)
		plan4Agg.AggFuncs = append(plan4Agg.AggFuncs, newFunc)
		schema4Agg.Append(col.Clone().(*expression.Column))
	}
	plan4Agg.SetChildren(p)
	plan4Agg.GroupByItems = gbyItems
	plan4Agg.SetSchema(schema4Agg)
	plan4Agg.collectGroupByColumns()
	return plan4Agg, aggIndexMap
}
