package main

import (
	"testing"
)

func TestCanMergeTop(t *testing.T) {
	if CanMergeTop([]string{}) {
		t.Error()
	}

	if !CanMergeTop([]string{"*"}) {
		t.Error()
	}
}

func TestEval(t *testing.T) {
	if eval(1, 2, "+") != 3 {
		t.Error()
	}

	if eval(1, 2, "-") != -1 {
		t.Error()
	}

	if eval(1, 2, "*") != 2 {
		t.Error()
	}

	if eval(1, 2, "/") != 0.5 {
		t.Error()
	}
}

func TestZipFull(t *testing.T) {
	operators, operands := zipFull([]string{"+"}, []float64{1, 2})
	if len(operators) != 0 || len(operands) != 1 || operands[0] != 3 {
		t.Error()
	}

	operators, operands = zipFull([]string{"(", "+"}, []float64{1, 2})
	if len(operators) != 0 || len(operands) != 1 || operands[0] != 3 {
		t.Error()
	}

	operators, operands = zipFull([]string{"(", "+", "(", "+"}, []float64{4, 1, 2})
	if len(operators) != 2 || len(operands) != 2 || operands[0] != 4 {
		t.Error()
	}
}

func TestShuntingYard(t *testing.T) {
	result := ShuntingYard([]string{"1", "+", "2"})
	if result != 3 {
		t.Error()
	}

	result = ShuntingYard([]string{"1", "+", "2", "*", "3", "+", "4"})
	if result != 11 {
		t.Error()
	}

	result = ShuntingYard([]string{"(", "1", "+", "2", ")", "*", "(", "3", "+", "4", ")"})
	if result != 21 {
		t.Error()
	}

	result = ShuntingYard([]string{"(", "1", "+", "2", "*", "(", "3", "+", "4", ")", ")"})
	if result != 15 {
		t.Error()
	}
}
