package main

import (
	"fmt"
)

func runningSum(nums []int) []int {
	var t, n = 0, len(nums)
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		t += nums[i]
		ans[i] = t
	}
	return ans
}
