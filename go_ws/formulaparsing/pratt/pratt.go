package pratt

func getInfixBinding(token OpToken) (int, int) {

	if token.op == "+" || token.op == "-" {
		return 3, 4
	} else if token.op == "*" || token.op == "/" {
		return 5, 6
	}

	return -1, -1
}

func getPrefixBinding(token OpToken) int {

	if token.op == "+" || token.op == "-" {
		return 8
	}

	return -1
}

func isText(token Token, expected string) bool {
	textToken, isText := token.(TextToken)
	return isText && textToken.value == expected
}

/*
parse all continuous tokens starting at nextI int, with binding power no less that the threshold
*/

func parseLevel(tokens []Token, nextI int, minBinding int) (ExprNode, int) {
	firstToken := tokens[nextI]

	if isText(firstToken, "(") {
		parsed, rightBracketI := parseLevel(tokens, nextI+1, 0)

		//TODO: assert that text is expected

		return parsed, rightBracketI + 1
	} else if opToken, isOpToken := firstToken.(OpToken); isOpToken {
		//TODO: assert only + and -
		rightBinding := getPrefixBinding(opToken)
		insideExpr, newNextI := parseLevel(tokens, nextI+1, rightBinding)

		return ExprTree{op: opToken.op, rhs: insideExpr}, newNextI
	}

	var expr ExprNode = ExprNum{value: firstToken.(NumToken).value}
	nextI += 1

	for {
		if nextI >= len(tokens) {
			return expr, nextI
		}

		if isText(tokens[nextI], ")") {
			return expr, nextI
		}

		opToken := tokens[nextI].(OpToken)

		nextBindingLeft, nextBindingRight := getInfixBinding(opToken)

		if nextBindingLeft < minBinding {
			return expr, nextI
		}

		nextI += 1

		//help decide if the sub-expr would bind to the current operator.
		//Also helps implement right associative operators
		rhsExpr, newNext := parseLevel(tokens, nextI, nextBindingRight)

		nextI = newNext
		expr = ExprTree{op: opToken.op, lhs: expr, rhs: rhsExpr}
	}
}

func Pratt(tokens []Token) ExprNode {

	parsed, _ := parseLevel(tokens, 0, 0)

	return parsed
}
