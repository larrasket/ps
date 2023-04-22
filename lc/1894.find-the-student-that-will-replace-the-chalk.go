package lc

func chalkReplacer(chalk []int, k int) int {
	var sum, cs, lk int64
	var res int
	var rk int64 = int64(k)
	for _, v := range chalk {
		sum += int64(v)
	}
	lk = rk % sum
	for i, v := range chalk {
		cs += int64(v)
		if cs > lk {
			res = i
			break
		}
	}
	return res

}
