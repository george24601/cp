package pratt

import "fmt"

type ExprNode interface {
	String() string
	Eval() float64
}

type ExprTree struct {
	op  string
	lhs ExprNode
	rhs ExprNode
}

func (tree ExprTree) String() string {
	return "(" + tree.op + " " + tree.lhs.String() + " " + tree.rhs.String() + ")"
}

func (tree ExprTree) Eval() float64 {

	if tree.op == "+" {
		return tree.lhs.Eval() + tree.rhs.Eval()
	} else if tree.op == "-" {
		return tree.lhs.Eval() - tree.rhs.Eval()
	} else if tree.op == "*" {
		return tree.lhs.Eval() * tree.rhs.Eval()
	} else if tree.op == "/" {
		return tree.lhs.Eval() / tree.rhs.Eval()
	}

	return -999
}

type ExprAtom struct {
	value float64
}

func (atom ExprAtom) String() string {
	return fmt.Sprintf("%.2f", atom.value)
}

func (atom ExprAtom) Eval() float64 {
	return atom.value
}
