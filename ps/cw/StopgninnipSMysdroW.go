package kata

import (
	"strings"
)

func SpinWords(str string) string {
	slz := strings.Fields(str)
	rvrs := func(in string) string {
		rn := []rune(in)
		for i, j := 0, len(rn)-1; i < j; i, j = i+1, j-1 {
			rn[i], rn[j] = rn[j], rn[i]
		}
		return string(rn)
	}
	for i, s := range slz {
		if len(s) >= 5 {
			slz[i] = rvrs(slz[i])
		}
	}
	return strings.Join(slz, " ")
}
