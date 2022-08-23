package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		var n int
		var mx int
		var mp = make(map[int]int)
		fmt.Scan(&n)
		for n > 0 {
			var tmp int
			fmt.Scan(tmp)
			mp[tmp]++
			n--
			if mp[tmp] > mx {
				mx = mp[tmp]
			}
		}
		if mx <= len(mp)+1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		t--
	}
}
