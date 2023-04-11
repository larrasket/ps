package lc

import (
	"fmt"
	"strings"
)

func lengthOfLastWord(s string) int {
	check := strings.Split(s, " ")
	n := len(check)
	for i := n - 1; i >= 0; i-- {
		if len(check[i]) > 0 {
			return len(check[i])
		}
	}
	return 0
}
