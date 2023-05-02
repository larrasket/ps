// package lc

func characterReplacement(s string, k int) int {
	ml, mc, l, r, f := 0, 0, 0, 0, map[byte]int{}

	for ; r < len(s); r++ {
		f[s[r]]++
		if f[s[r]] > mc {
			mc = f[s[r]]
		}
		for r-l+1-mc > k {
			f[s[l]]--
			l++
		}
		if r-l+1 > ml {
			ml = r - l + 1
		}
	}
	return ml
}
