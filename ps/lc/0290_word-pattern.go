// package lc

import "strings"

func wordPattern(pattern string, s string) bool {
	mp := map[rune]string{}
	rmp := map[string]rune{}

	lst := strings.Split(s, " ")

	if len(lst) != len(pattern) {
		return false
	}

	var i int
	for _, value := range lst {

		if v, ok := rmp[value]; ok && rune(pattern[i]) != v {
			return false
		}

		r := rune(pattern[i])
		v, ok := mp[r]
		if ok && value != v {
			return false
		}
		mp[r] = value

		rmp[value] = r

		i++
	}
	return true
}
