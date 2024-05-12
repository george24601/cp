package shasta

// basePlan implements base Plan interface.
// Should be used as embedded struct in Plan implementations.
type basePlan struct {
	tp string
	id int
	//	ctx   context.Context
}

// Plan is the description of an execution flow.
// It is created from ast.Node first, then optimized by the optimizer,
// finally used by the executor to create a Cursor which executes the statement.
type Plan interface {
	// Get the schema.
	//	Schema() *expression.Schema
	// replaceExprColumns replace all the column reference in the plan's expression node.
	//replaceExprColumns(replace map[string]*expression.Column)

	//context() context.Context
}

// LogicalPlan is a tree of logical operators.
// We can do a lot of logical optimizations to it, like predicate pushdown and column pruning.
type LogicalPlan interface {
	Plan

	// PredicatePushDown pushes down the predicates in the where/on/having clauses as deeply as possible.
	// It will accept a predicate that is an expression slice, and return the expressions that can't be pushed.
	// Because it might change the root if the having clause exists, we need to return a plan that represents a new root.
	PredicatePushDown([]Expression) ([]Expression, LogicalPlan)

	// PruneColumns prunes the unused columns.
	PruneColumns([]Column)

	// findColumn finds the column in basePlan's schema.
	// If the column is not in the schema, returns an error.
	//findColumn(*ast.ColumnName) (*expression.Column, int, error)

	// Get all the children.
	Children() []LogicalPlan

	// SetChildren sets the children for the plan.
	SetChildren(...LogicalPlan)
}

type baseLogicalPlan struct {
	basePlan

	//taskMap   map[string]task
	self      LogicalPlan
	maxOneRow bool
	children  []LogicalPlan
}
