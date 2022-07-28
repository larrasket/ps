package kata

import (
	"strings"
	"unicode"
)

func FindMissingLetter(chars []rune) rune {

	alpha := "abcdefghijklmnopqrstuvwxyz"
	if unicode.IsUpper(chars[0]) {
		alpha = strings.ToUpper(alpha)
	}
	start := strings.IndexRune(alpha, chars[0])
	end := strings.IndexRune(alpha, chars[len(chars)-1])
	searchalpha := alpha[start : end+1]
	searchstring := string(chars)
	for _, value := range searchalpha {
		if !strings.ContainsRune(searchstring, value) {
			return value
		}
	}
	return 'a'
}
