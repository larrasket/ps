package main

import (
	"fmt"
)

func main() {
	s := []int{1, 2, 3, 4}

	for _, value := range s {
		value++
	}

	for _, value := range s {
		fmt.Print(value)
	}

}
