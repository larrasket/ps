// package lc

import (
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
	ans := strings.Builder{}
	csh := map[int]int{}
	getAs := func(n int) int {
		if val, ok := csh[n]; ok {
			return val
		}
		l := n
		for n > 0 {
			l = n
			n /= 10
		}
		csh[n] = l
		return l
	}
	sorty := func(i, j int) bool {
		fi, fj := getAs(nums[i]), getAs(nums[j])
		if fi == fj && nums[i] != nums[j] {
			si, sj := strconv.Itoa(nums[i]), strconv.Itoa(nums[j])
			fzi := strings.IndexRune(si, '0')
			if fzi != -1 {
				fi, _ = strconv.Atoi(si[:fzi])
			} else {
				return false
			}
			fzj := strings.IndexRune(sj, '0')
			if fzj != -1 {
				fj, _ = strconv.Atoi(sj[:fzj])
			} else {
				return true
			}
		}
		if fi == fj {
			return nums[i] < nums[j]
		}
		return fi < fj
	}
	sort.Slice(nums, sorty)
	n := len(nums) - 1
	for ; n >= 0; n-- {
		ans.WriteString(strconv.Itoa(nums[n]))
	}
	return ans.String()
}
