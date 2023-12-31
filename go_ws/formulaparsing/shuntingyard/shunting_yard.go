package shuntingyard

import "strconv"

/*
* invariants
	* priority on the operator should be strictly increasing, ignoring the brackets
*/

func reduceOne(operators []string, operands []float64) ([]string, []float64) {

	popped := operands[len(operands)-2:]
	operands = operands[:len(operands)-2]

	operator := operators[len(operators)-1]
	operators = operators[:len(operators)-1]

	newVal := eval(popped[0], popped[1], operator)

	operands = append(operands, newVal)
	return operators, operands
}

func reduceAll(operators []string, operands []float64) ([]string, []float64) {

	for len(operators) > 0 && operators[len(operators)-1] != "(" {
		operators, operands = reduceOne(operators, operands)
	}

	if len(operators) > 0 {
		operators = operators[:len(operators)-1]
	}

	return operators, operands
}

var operatorToPriority = map[string]int{
	"+": 5,
	"-": 5,
	"*": 6,
	"/": 6,
}

func shouldReduce(operators []string, nextOperator string) bool {
	if len(operators) == 0 {
		return false
	}

	prevOperator := operators[len(operators)-1]
	return operatorToPriority[prevOperator] >= operatorToPriority[nextOperator]
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
		} else if token == ")" {
			operators, operands = reduceAll(operators, operands)
		} else {
			_, isNextOperator := operatorToPriority[token]

			if isNextOperator {
				if shouldReduce(operators, token) {
					operators, operands = reduceOne(operators, operands)
				}

				operators = append(operators, token)
			} else {
				operand, _ := strconv.ParseFloat(token, 64)
				operands = append(operands, operand)
			}
		}
	}

	if len(operands) > 1 {
		operators, operands = reduceAll(operators, operands)
	}

	//TODO: check invariants for error handling

	return operands[0]
}
