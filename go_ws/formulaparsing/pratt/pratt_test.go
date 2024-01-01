package pratt

import (
	"testing"
)

func TestGetBinding(t *testing.T) {
	lhs, rhs := getInfixBinding(OpToken{op: "+"})

	if !(lhs == 3 && rhs == 4) {
		t.Error()
	}
	lhs, rhs = getInfixBinding(OpToken{op: "*"})

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
	if parsed.String() != "(+ (* 2.00 3.00) 4.00)" {
		t.Error()
	}

	leftAssociate := []Token{NumToken{value: 2}, OpToken{op: "*"}, NumToken{value: 3}, OpToken{op: "*"}, NumToken{value: 4}}

	if Pratt(leftAssociate).String() != "(* (* 2.00 3.00) 4.00)" {
		t.Error()
	}

	brackets := []Token{NumToken{value: 2}, OpToken{op: "*"}, TextToken{value: "("}, NumToken{value: 3}, OpToken{op: "+"}, NumToken{value: 4}, TextToken{value: ")"}}

	parsedBrackets := Pratt(brackets)
	if parsedBrackets.String() != "(* 2.00 (+ 3.00 4.00))" {
		t.Error()
	}

	unary := []Token{OpToken{op: "-"}, TextToken{value: "("}, NumToken{value: 3}, OpToken{op: "+"}, NumToken{value: 4}, TextToken{value: ")"}}

	if Pratt(unary).String() != "(- (+ 3.00 4.00))" {
		t.Error()
	}

	onlyBrackets := []Token{TextToken{value: "("}, TextToken{value: "("}, TextToken{value: "("}, NumToken{value: 3}, TextToken{value: ")"}, TextToken{value: ")"}, TextToken{value: ")"}}

	if Pratt(onlyBrackets).String() != "3.00" {
		t.Error()
	}

}
