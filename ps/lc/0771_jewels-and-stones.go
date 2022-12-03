// package lc

import "strings"

func numJewelsInStones(jewels string, stones string) int {
	var ans int
	for _, value := range stones {
		if strings.ContainsRune(jewels, value) {
			ans++
		}
	}
	return ans
}
