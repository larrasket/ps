package main

import "fmt"

func printPrice(twe, tw string, tar int, sum func(int) int) {
	kayakPrice := 275.00
	kayakTax := kayakPrice * 0.2
	fmt.Println("Price:", kayakPrice, "Tax:", kayakTax)
}
func main() {
	fmt.Println("About to call function")
	printPrice("wq", "wqw", 12, sum)
	fmt.Println("Function complete")
}

func sum(ar int) int {
	return 12
}
