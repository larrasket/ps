package lc

import "strings"

func prefixCount(words []string, pref string) int {
	var ans int
	for _, w := range words {
		if strings.HasPrefix(w, pref) {
		ans++;
		}
	}
	return ans
}
