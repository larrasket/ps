package lc

import "strconv"

func simplifiedFractions(n int) []string {
	var de, ne, nn float64 = 1, 2, float64(n)
	var ans []string
	mp := map[float64]bool{}
	for ne <= nn {
		if de >= ne {
			de, ne = 1, ne+1
			continue
		}
		if !mp[(de / ne)] {
			mp[(de / ne)] = true
			ans = append(ans, trns(de, ne))
		}
		de++
	}
	return ans
}

func trns(d, n float64) string {
	return strconv.Itoa(int(d)) + "/" + strconv.Itoa(int(n))
}
