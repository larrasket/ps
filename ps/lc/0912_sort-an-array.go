package lc

func part(arr []int, low, high int) ([]int, int) {
	pivout, i := arr[high], low
	for j := low; j < high; j++ {
		if arr[j] < pivout {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[high] = arr[high], arr[i]
	return arr, i
}

func q(arr []int, l, h int) []int {
	if l < h {
		arr, p := part(arr, l, h)
		arr = q(arr, l, p-1)
		arr = q(arr, p+1, h)
	}
	return arr
}

func sortArray(nums []int) []int {
	return q(nums, 0, len(nums)-1)
}
