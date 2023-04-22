package lc

func rowAndMaximumOnes(mat [][]int) []int {
	ans := []int{0, 0}
	mp := map[int]int{}
	for i, v := range mat {
		for _, vv := range v {
			if vv == 1 {
				mp[i]++
			}
		}
	}
	var max int = 0
	for key, value := range mp {
		if value > max {
			max = value
			ans[0] = key
			ans[1] = value
		}
	}
	return ans
}
