package main

import (
	"fmt"
	"sort"
	"strings"
)

func InArray(array1 []string, array2 []string) []string {
	a3 := strings.Join(array2, "")
	ans := []string{}
	mp := map[string]bool{}
	for _, value := range array1 {
		if strings.Contains(a3, value) && mp[value] == false {
			ans = append(ans, value)
		}
	}
	sort.Strings(ans)
	return ans
}

func main() {
	var a1 = []string{"live", "arp", "strong"}
	var a2 = []string{"lively", "alive", "harp", "sharp", "armstrong"}
	strings.
		fmt.Println(InArray(a1, a2))
}
