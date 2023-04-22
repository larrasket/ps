package lc

func minimumOperations(nums []int) int {
	mp := map[int]int{}
	for _, v := range nums {
		if v != 0 {
			mp[v] = 1
		}
	}
	return len(mp)
}
