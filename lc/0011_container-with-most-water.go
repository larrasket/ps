// package lc

import "math"

func maxArea(height []int) int {
	res, l, r := 0, 0, len(height)-1

	for l < r {
		tres := (r - l) * int(math.Min(float64(height[l]), float64(height[r])))
		res = int(math.Max(float64(tres), float64(res)))
		if height[r] > height[l] {
			l++
		} else {
			r--
		}
	}
	return res

}
