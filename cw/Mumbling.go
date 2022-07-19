package kata

import (
	"strings"
	"unicode"
)

func Accum(s string) string {
	var str strings.Builder
	for i, c := range s {
		u, l := unicode.ToUpper(c), unicode.ToLower(c)
		str.WriteRune(u)
		i--
		for i+1 > 0 {
			str.WriteRune(l)
			i--
		}
		str.WriteRune('-')
	}
	return str.String()[:str.Len()-1]
}
