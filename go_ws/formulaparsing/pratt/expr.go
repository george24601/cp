package pratt

import "fmt"

type ExprNode interface {
	String() string
}

type ExprTree struct {
	op  string
	lhs ExprNode
	rhs ExprNode
}

func (tree ExprTree) String() string {
	toReturn := "("

	toReturn += tree.op

	if tree.lhs != nil {
		toReturn += " " + tree.lhs.String()
	}

	if tree.rhs != nil {
		toReturn += " " + tree.rhs.String()
	}

	toReturn += ")"
	return toReturn
}

type ExprNum struct {
	value float64
}

type ExprId struct {
	id string
}

func (atom ExprNum) String() string {
	return fmt.Sprintf("%.2f", atom.value)
}

func (id ExprId) String() string {
	return id.id
}

func (atom ExprNum) Eval() float64 {
	return atom.value
}
