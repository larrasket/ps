package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	finfo, err := os.Stat("go.mod")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Print(float32(finfo.Size() / 1024))
}
