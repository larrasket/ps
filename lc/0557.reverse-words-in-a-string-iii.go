package lc

import "strings"

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func reverseWords(s string) string {
	var ans strings.Builder
	words := strings.Split(s, " ")
	for key, _ := range words {
		if !strings.ContainsRune(words[key], ' ') {
			words[key] = Reverse(words[key])
		}
		ans.WriteString(words[key])
		ans.WriteRune(' ')
	}
	return ans.String()[:ans.Len()-1]
}
