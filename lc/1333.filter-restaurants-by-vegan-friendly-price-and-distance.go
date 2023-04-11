// package lc

import (
	"fmt"
	"sort"
)

func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
	ans := []int{}
	for key, value := range restaurants {
		if (veganFriendly == 1 && value[2] != veganFriendly) || value[4] > maxDistance || value[3] > maxPrice {
			restaurants[key][1] = -1
		}
	}

	// fmt.Println(restaurants)
	sort.Slice(restaurants, func(i, j int) bool {
		if restaurants[i][1] == restaurants[j][1] {
			return restaurants[i][0] > restaurants[j][0]
		}

		return restaurants[i][1] > restaurants[j][1]
	})
	for _, value := range restaurants {
		if value[1] == -1 {
			break
		}
		ans = append(ans, value[0])
	}
	return ans
}
