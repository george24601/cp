package pratt

import (
	"testing"
)

func TestExpr(t *testing.T) {
	atom2 := ExprNum{value: 2}
	atom3 := ExprNum{value: 3}
	atom4 := ExprNum{value: 4}

	plus := ExprTree{op: "+", lhs: atom2, rhs: atom3}
	multi := ExprTree{op: "*", lhs: plus, rhs: atom4}

	if multi.String() != "(* (+ 2.00 3.00) 4.00)" {
		t.Error()
	}
}
