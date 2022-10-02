package main

import (
	"fmt"
	"os"
)

func main() {
	ferr, _ := os.Open("go.mod")
	ferr.Close()
	defer ferr.Close()
	fmt.Print("ewff")

}
