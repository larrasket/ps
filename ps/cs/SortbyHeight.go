import "sort"

func solution(a []int) []int {
	arr := make([]int, len(a))
	copy(arr, a)
	sort.Ints(arr)
	var i int

	for k, v := range arr {
		if v != -1 {
			i = k
			break
		}
	}

	for k, v := range a {
		if v == -1 {
			continue
		}
		a[k] = arr[i]
		i++
	}

	return a
}
