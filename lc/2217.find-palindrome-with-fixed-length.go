package main

import (
	"fmt"
)


// 101
// 1001
// 10001
// 100001
// 1 -> 0
// 2 -> 1
// 3 -> 2
// ....
// x``
func kthPalindrome(queries []int, intLength int) []int64 {
	s := 1
	e := intLength % 2 == 0
	q := 1
	if !e {
		var mi int = intLength / 2
	}
}
