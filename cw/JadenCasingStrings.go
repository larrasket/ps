package main

import "unicode"

func ToJadenCase(str string) string {
	s := []rune(str)
	for i, c := range s {
		if c == ' ' {
			s[i+1] = unicode.ToUpper(s[i+1])
		}
	}
	s[0] = unicode.ToUpper(s[0])
	return string(s)
}
