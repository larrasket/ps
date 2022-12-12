// package lc

import "strconv"

func fizzBuzz(n int) []string {
	arr := make([]string, n)
	for key, _ := range arr {
		tk := key + 1
		switch {
		case tk%3 == 0 && tk%5 == 0:
			arr[key] = "FizzBuzz"
		case tk%3 == 0:
			arr[key] = "Fizz"
		case tk%5 == 0:
			arr[key] = "Buzz"
		default:
			arr[key] = strconv.Itoa(tk)
		}
	}
	return arr
}
