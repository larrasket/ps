package main

import (
	"fmt"
)

func main() {
	price4, _, _ := f()
	fmt.Println(price4)
}

func f() (int, int, int) {
	return 42, 53, 5
}
