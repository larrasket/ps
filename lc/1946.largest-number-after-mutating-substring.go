package lc

func maximumNumber(num string, change []int) string {
	runes, cont := []rune(num), false
	for i, v := range runes {
		c := int(v - '0')
		if c < change[c] {
			runes[i] = rune(change[c] + '0')
			cont = true
		} else if c == change[c] && cont {
			cont = true
		} else if cont {
			break
		}
	}
	return string(runes)
}
