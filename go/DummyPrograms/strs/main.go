package main

import (
	"fmt"
	"strings"
)

func main() {
	v := "eqe"
	e := "eqE"
	fmt.Println(strings.EqualFold(v, e))

}
