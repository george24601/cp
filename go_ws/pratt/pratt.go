package formulaparsing

import "fmt"

type Token interface {
	String() string
}

type TokenAtom struct {
	value float64
}

func (atom TokenAtom) String() string {
	return fmt.Sprintf("%f", atom.value)
}

func parse(tokens []Token, nextI int) (string, int) {
	lhs := tokens[nextI]

	switch lhs.(type) {
	case TokenAtom:
		return lhs.String(), nextI + 1
	}

	return "", 0
}

func Pratt(tokens []Token) string {

	parsed, _ := parse(tokens, 0)

	return parsed
}
