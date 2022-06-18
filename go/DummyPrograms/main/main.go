package main

import "fmt"

func main() {
	PrintHello()
	for i := 0; i < 5; i++ {
		i = i
		PrintNumber(i)
	}
}

func PrintHello() {
	fmt.Print("Hello, Go")
}

func PrintNumber(number int) {
	fmt.Print(number)
}
