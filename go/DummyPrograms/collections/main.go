package main

import "fmt"

func main() {
	products := [4]string{"Kayak", "Lifejacket", "Paddle", "Hat"}
	allNames := products[:]
	someNames := make([]string, 2)

	type ta struct {
		count int
		string
	}

	aas := new(ta)
	aas.string = "wqw"

	copy(someNames, allNames)
	fmt.Println("someNames:", someNames)
	fmt.Println("allNames", allNames)
}

func Shbalnga(khaled, ahmed, samy string) (int, int) {

	return 1, 2

}
