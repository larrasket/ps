package lc

import "strings"

func alphabetBoardPath(target string) string {
	board := [...]string{"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"}
	m := make(map[rune][2]int)
	var ans strings.Builder
	i, j := 0, 0
	for _, value := range target {
		// find desired index;
		r, c := 0, 0
		if val, ok := m[value]; !ok {
			for key, word := range board {
				r = key
				c = strings.IndexRune(word, value)
				if c != -1 {
					break
				}
			}
		} else {
			r, c = val[0], val[1]
		}
		if value == 'z' {
			for j != c {

				if j > c {
					j--
					ans.WriteRune('L')
				} else {
					j++
					ans.WriteRune('R')
				}
			}

			for i != r {
				if i > r {
					i--
					ans.WriteRune('U')
				} else {
					i++
					ans.WriteRune('D')
				}
			}
		} else {

			for i != r {
				if i > r {
					i--
					ans.WriteRune('U')
				} else {
					i++
					ans.WriteRune('D')
				}
			}

			for j != c {

				if j > c {
					j--
					ans.WriteRune('L')
				} else {
					j++
					ans.WriteRune('R')
				}
			}

		}
		ans.WriteRune('!')
	}
	return ans.String()
}
