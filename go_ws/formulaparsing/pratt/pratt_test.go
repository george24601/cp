package pratt

import (
	"testing"
)

func TestGetBinding(t *testing.T) {
	lhs, rhs := getBinding(OpToken{op: "+"})

	if !(lhs == 3 && rhs == 4) {
		t.Error()
	}
	lhs, rhs = getBinding(OpToken{op: "*"})

	if !(lhs == 5 && rhs == 6) {
		t.Error()
	}
}

func TestIsText(t *testing.T) {
	if !isText(TextToken{value: "("}, "(") {
		t.Error()
	}
}

func TestParse(t *testing.T) {
	sequential := []Token{NumToken{value: 2}, OpToken{op: "*"}, NumToken{value: 3}, OpToken{op: "+"}, NumToken{value: 4}}

	parsed := Pratt(sequential)
	if parsed.Eval() != 10 {
		t.Error()
	}

	if parsed.String() != "(+ (* 2.00 3.00) 4.00)" {
		t.Error()
	}

	leftAssociate := []Token{NumToken{value: 2}, OpToken{op: "*"}, NumToken{value: 3}, OpToken{op: "*"}, NumToken{value: 4}}

	if Pratt(leftAssociate).String() != "(* (* 2.00 3.00) 4.00)" {
		t.Error()
	}

	brackets := []Token{NumToken{value: 2}, OpToken{op: "*"}, TextToken{value: "("}, NumToken{value: 3}, OpToken{op: "+"}, NumToken{value: 4}, TextToken{value: ")"}}

	if Pratt(brackets).Eval() != 14 {
		t.Error()
	}
}
