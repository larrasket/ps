package store

import (
	"fmt"
)

type Product struct {
	Name, Category string
	price          int
}

func Printer() {
	fmt.Print("Hello")
}
