package main

//
// 3 4 5 6 7 2 1

func longestConsecutive(nums []int) int {
	mp := map[int]int{}
	mpmx := map[int]int{}
	for _, v := range nums {
		mp[v] = v + 1
	}
	var m int
	for _, v := range nums {
		var tmpn int
		var okv bool
		mv, okv := mp[v]
		if mxv, ok := mpmx[mv]; ok {
			tmpn = mxv + 1
			mpmx[v] = tmpn
		} else {
			for okv {
				tmpn++
				mv, okv = mp[mv]
			}
		}
		mpmx[v] = tmpn

		m = max(m, tmpn)
		if m == len(nums) {
			return m
		}

		i := 1
		for tmpn > 0 {
			mpmx[v + i] = tmpn - 1
			tmpn--
			i++
		}
	}
	return m
}
