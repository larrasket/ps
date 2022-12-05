// package lc

import "strings"

func defangIPaddr(address string) string {
	sl := strings.Split(address, ".")
	b := strings.Builder{}
	for _, value := range sl {
		b.WriteString(value)
		b.WriteString("[.]")
	}
	return b.String()[:len(b.String())-3]
}
