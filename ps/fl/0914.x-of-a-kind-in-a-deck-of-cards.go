package main

import "fmt"

func hasGroupsSizeX(deck []int) bool {
	mp := map[int]int{}
	for _, v := range deck {
		mp[v]++
	}
	mv := mp[deck[0]]
	if len(mp) == 1 {
		return false
	}
	for _, v := range mp {
		if v != mv && !(v%2 == 0 || mv%2 == 0) {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(hasGroupsSizeX([]int{1, 1, 2, 2, 2, 2}))
}
