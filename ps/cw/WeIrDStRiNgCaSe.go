package kata

import (
	"strings"
	"unicode"
)

func toWeirdCase(str string) string {
	str = strings.ToLower(str)
	strs := strings.Split(str, " ")
	bldr := strings.Builder{}
	for k, value := range strs {
		rnvalue := []rune(value)
		for key, othervalue := range rnvalue {
			if key%2 == 0 {
				rnvalue[key] = unicode.ToUpper(othervalue)
			}
		}
		bldr.WriteString(string(rnvalue))
		if k != len(strs)-1 {
			bldr.WriteRune(' ')
		}
	}
	return bldr.String()
}
