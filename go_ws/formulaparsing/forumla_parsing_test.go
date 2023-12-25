package formulaparsing

import (
	"testing"
)

func TestShouldReduce(t *testing.T) {
	if shouldReduce([]string{}, "*") {
		t.Error()
	}

	if !shouldReduce([]string{"*"}, "+") {
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

func TestReduceOne(t *testing.T) {
	operators, operands := reduceOne([]string{"+", "*"}, []float64{1, 2, 3})
	if len(operators) != 1 || len(operands) != 2 || operands[1] != 6 {
		t.Error()
	}
}

func TestReduceAll(t *testing.T) {
	operators, operands := reduceAll([]string{"+"}, []float64{1, 2})
	if len(operators) != 0 || len(operands) != 1 || operands[0] != 3 {
		t.Error()
	}

	operators, operands = reduceAll([]string{"+", "*"}, []float64{1, 2, 3})
	if len(operators) != 0 || len(operands) != 1 || operands[0] != 7 {
		t.Error()
	}

	operators, operands = reduceAll([]string{"(", "+"}, []float64{1, 2})
	if len(operators) != 0 || len(operands) != 1 || operands[0] != 3 {
		t.Error()
	}

	operators, operands = reduceAll([]string{"(", "+", "(", "+"}, []float64{4, 1, 2})
	if len(operators) != 2 || len(operands) != 2 || operands[0] != 4 {
		t.Error()
	}
}

func TestShuntingYard(t *testing.T) {
	result := ShuntingYard([]string{"1", "+", "2"})
	if result != 3 {
		t.Error()
	}

	result = ShuntingYard([]string{"1", "+", "2", "*", "3"})
	if result != 7 {
		//fmt.Println(result)
		t.Error()
	}

	result = ShuntingYard([]string{"1", "+", "2", "*", "3", "+", "4"})
	if result != 11 {
		//fmt.Println(result)
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
