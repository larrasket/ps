// package lc

import (
	"fmt"
	"strconv"
	"strings"
	"unicode"
)

func subdomainVisits(cpdomains []string) []string {
	ans := []string{}
	fend := func(s int) (i int) {
		for _, c := range cpdomains[s] {
			if !unicode.IsDigit(c) {
				break
			}
			i++
		}
		return i - 1
	}
	mp := map[string]int{}
	for i, _ := range cpdomains {
		end := fend(i)
		n, _ := strconv.Atoi(cpdomains[i][:end+1])
		d := strings.Count(cpdomains[i], ".")
		mp[cpdomains[i][end+2:]] += n
		if d == 1 {
			mp[cpdomains[i][strings.Index(cpdomains[i], ".")+1:]] += n
		} else {
			dt := strings.Index(cpdomains[i], ".")
			mp[cpdomains[i][dt+1:]] += n
			dt2 := strings.Index(cpdomains[i][dt+1:], ".")
			mp[cpdomains[i][dt+1:][dt2+1:]] += n
		}
	}
	for key, value := range mp {
		ans = append(ans, fmt.Sprintf("%d %s", value, key))

	}
	return ans
}
