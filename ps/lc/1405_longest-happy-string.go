// package lc

import (
	"sort"
	"strings"
)

func longestDiverseString(a int, b int, c int) string {
	ans := strings.Builder{}
	lst := make([]struct {
		int
		rune
	}, 3)
	lst[0].rune, lst[0].int = 'a', a
	lst[1].rune, lst[1].int = 'b', b
	lst[2].rune, lst[2].int = 'c', c

	toadd := 2
	added := lst[toadd]
	added.int = 0
	for {
		if toadd < 0 {
			return ans.String()
		}

		if added.int == 2 {
			if toadd >= 1 && lst[toadd-1].int > 0 {
				lst[toadd-1].int--
				ans.WriteRune(lst[(toadd - 1)].rune)
				added.int = 0
			} else if toadd >= 2 && lst[toadd-2].int > 0 {
				lst[(toadd-2)].int--
				ans.WriteRune(lst[toadd-2].rune)
				added.int = 0
			} else {
				return ans.String()
			}
			continue
		}
		if lst[toadd].int == 0 {
			toadd--
			if toadd >= 0 {
				added = lst[toadd]
				if ans.String()[ans.Len()-1] == byte(added.rune) {
					added.int = 1
				} else {
					added.int = 0
				}
			}
			continue
		}
		ans.WriteRune(lst[toadd].rune)
		added.int++
		lst[toadd].int--

	}
	return ans.String()
}
