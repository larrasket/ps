package main

func TwoSum(numbers []int, target int) [2]int {
	m := map[int]int{}
	for key, value := range numbers {
		_, err := m[target-value]
		if err {
			return [2]int{key, m[target-value]}
		}
		m[value] = key
	}
	return [2]int{}
}
