package kata

import (
	"math"
	"strings"
)

func FindShort(s string) int {
	var rs int = math.MaxInt
	slz := strings.Fields(s)
	for _, value := range slz {
		if len(value) < rs {
			rs = len(value)
		}
	}
	return rs
}
