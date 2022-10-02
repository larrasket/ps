package main

import (
	"fmt"
	. "packges/fmt"
	"packges/store"
)

func main() {
	pr := store.Product{
		Name:     "o",
		Category: "fr",
	}
	fmt.Print(ToCurrency(12))
	fmt.Print(pr)
	store.Printer()
}
