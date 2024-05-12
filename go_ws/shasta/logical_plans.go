package shasta

// LogicalProjection represents a select fields plan.
type LogicalProjection struct {
	//	logicalSchemaProducer

	Exprs []Expression
}

// LogicalSelection represents a where or having predicate.
type LogicalSelection struct {
	//	baseLogicalPlan

	// Originally the WHERE or ON condition is parsed into a single expression,
	// but after we converted to CNF(Conjunctive normal form), it can be
	// split into a list of AND conditions.
	Conditions []Expression
}

// DataSource represents a tablescan without condition push down.
type DataSource struct {
	//	logicalSchemaProducer

	tableInfo *TableInfo
	Columns   *ColumnInfo

	//	TableAsName *model.CIStr

	//LimitCount *int64

	// pushedDownConds are the conditions that will be pushed down to coprocessor.
	//pushedDownConds []expression.Expression
}
