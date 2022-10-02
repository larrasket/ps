package main

import (
	"fmt"
	//math"
)

func main() {
	kayak := 275
	soccerBall := 19.50
	total := float64(kayak) + soccerBall
	if true {
		fmt.Println(total)
	}
	r := "wq3"
	switch r {
	case "wq":
		fmt.Print(true || false)
	default:
		fmt.Print("eqe")
	}

}
