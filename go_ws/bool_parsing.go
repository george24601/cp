package main

type BoolNode struct {
	State     bool
	HasNegate bool
	Children  []*BoolNode
}
