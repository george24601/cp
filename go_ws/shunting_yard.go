package main

import (
	"strconv"
)

/*
* invariants
	* operators stacks has only +, -, *, / and (
	* after consuming all )s, operators has only + and -
	* at most 1 * or / on the stack
*/

func zipFull(operators []string, operands []float64) ([]string, []float64) {

	for len(operators) > 0 && operators[len(operators)-1] != "(" {

		popped := operands[len(operands)-2:]
		operands = operands[:len(operands)-2]

		operator := operators[len(operators)-1]
		operators = operators[:len(operators)-1]

		newVal := eval(popped[0], popped[1], operator)

		operands = append(operands, newVal)
	}

	if len(operators) > 0 {
		operators = operators[:len(operators)-1]
	}

	return operators, operands
}

func CanMergeTop(operators []string) bool {
	if len(operators) == 0 {
		return false
	}

	operator := operators[len(operators)-1]
	return operator == "*" || operator == "/"
}

func eval(lhs float64, rhs float64, op string) float64 {
	if op == "+" {
		return lhs + rhs
	} else if op == "-" {
		return lhs - rhs
	} else if op == "*" {
		return lhs * rhs
	} else if op == "/" {
		//TODO: 0 check
		return lhs / rhs
	} else {
		//TODO: error
		return -1
	}
}

func ShuntingYard(tokens []string) float64 {
	operators := make([]string, 0, 100)
	operands := make([]float64, 0, 100)

	for _, token := range tokens {
		if token == "(" {
			operators = append(operators, token)
		} else if token == "*" || token == "/" {
			operators = append(operators, token)
		} else if token == "+" || token == "-" {
			operators = append(operators, token)
		} else if token == ")" {
			operators, operands = zipFull(operators, operands)

		} else {
			operand, _ := strconv.ParseFloat(token, 64)
			if CanMergeTop(operators) {
				lastOperatorI := len(operators) - 1
				operator := operators[lastOperatorI]
				operators = operators[:lastOperatorI]
				lastOperandI := len(operands) - 1
				lhs := operands[lastOperandI]
				operands = operands[:lastOperandI]

				operands = append(operands, eval(lhs, operand, operator))
			} else {
				operands = append(operands, operand)
			}
		}
	}

	zipFull(operators, operands)

	//TODO: check invariants for error handling

	return operands[0]
}
