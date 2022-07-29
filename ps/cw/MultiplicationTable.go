package kate

// import (
// 	"fmt"
// )

func MultiplicationTable(size int) [][]int {
	s := make([][]int, size)
	for k1 := range s {
		s[k1] = make([]int, size)

	}
	for k1, value := range s {
		s[k1] = make([]int, size)
		for k2 := range value {
			s[k1][k2] = (k1 + 1) * (k2 + 1)
		}
	}
	return s
}
