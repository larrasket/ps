package lc

func minimalKSum(nums []int, k int) int64 {
	sum := int64((k * (k + 1)) / 2)

	for _, value := range nums {
		if value <= k {
			sum -= int64(value)
			sum += int64(k + 1)
			k = k + 1
		}
	}
	return sum
}
