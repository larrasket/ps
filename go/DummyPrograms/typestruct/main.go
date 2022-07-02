package main

import (
	"fmt"
)

func main() {
	type raf struct {
		string
		count int
	}
	aef := raf{
		string: "awd",
		count:  13,
	}
	fmt.Print(aef.string)
}
