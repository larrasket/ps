package kata

func Multiple3And5(number int) int {
	var ans int
	for i := 1; i < number; i++ {
		if i%3 == 0 || i%5 == 0 {
			ans += i
		}
	}
	return ans
}
