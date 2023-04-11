// package lc

import (
	"strings"
	"unicode"
)

func detectCapitalUse(word string) bool {
	up, down := strings.ToUpper(word), strings.ToLower(word)
	if word == up || word == down {
		return true
	}
	ts := string(unicode.ToUpper(rune(down[0]))) + down[1:]
	return ts == word
}
