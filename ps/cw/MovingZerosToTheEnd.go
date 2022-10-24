package kata

func MoveZeros(arr []int) []int {
	index := 0
	for _, value := range arr {
		if value != 0 {
			arr[index] = value
			index++
		}

	}
	for i := index; i < len(arr); i++ {
		arr[i] = 0
	}
	return arr
}
