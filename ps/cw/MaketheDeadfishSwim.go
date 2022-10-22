package kata

func Parse(data string) []int {
	ans, v := []int{}, 0

	for _, value := range data {
		switch value {
		case 'i':
			v++
		case 'd':
			v--
		case 's':
			v *= v
		case 'o':
			ans = append(ans, v)
		}
	}
	return ans
}
