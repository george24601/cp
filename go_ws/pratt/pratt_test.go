package formulaparsing

import (
	"testing"
)

func TestExpr(t *testing.T) {
	_, nextI := parse([]Token{TokenAtom{value: 1}}, 0)
	if nextI != 1 {
		t.Error()
	}
}
