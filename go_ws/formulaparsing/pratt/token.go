package pratt

type Token interface {
}

type NumToken struct {
	value float64
}

type OpToken struct {
	op string
}

type TextToken struct {
	value string
}
