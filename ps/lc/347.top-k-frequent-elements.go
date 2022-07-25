package main

import (
	"fmt"
	"sort"
)

func main() {
	m := map[string]int{"zz": 221, "eq": 11}
	for key, value := range m {
		fmt.Println(key, value)
	}
}

func topKFrequent(nums []int, k int) []int {
	mmm := map[int]int{}
	type dummy struct {
		value int
		key   int
	}
	m := []dummy{}
	ans := make([]int, k)
	for _, value := range nums {
		mmm[value]++
	}
	for key, value := range mmm {
		m = append(m, dummy{value, key})
	}
	sort.Slice(m, func(i, j int) bool { return m[i].value < m[j].value })
	for i := 0; i < k; i++ {
		ans[i] = m[i].key
	}
	return ans
}
