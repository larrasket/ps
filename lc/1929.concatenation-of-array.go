package lc

import (
	"fmt"
)

func getConcatenation(nums []int) []int {
	return append(nums, nums...)

}
