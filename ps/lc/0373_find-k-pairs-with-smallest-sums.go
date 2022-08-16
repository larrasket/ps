// package lc

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	ans := [][]int{}
	for _, value := range nums1 {
		for _, value2 := range nums2 {
			ans = append(ans, []int{value, value2})
			k--
			if k == 0 {
				break
			}
		}
		if k == 0 {
			break
		}
	}
	return ans
}
