import (
	"strconv"
)

func diffWaysToCompute(input string) []int {
	var res []int

	for i := 0; i < len(input); i++ {
		c := input[i]

		if c == '-' || c == '+' || c == '*' {
			l := input[:i]
			r := input[i+1:]

			lft := diffWaysToCompute(l)
			rt := diffWaysToCompute(r)

			for _, x := range lft {
				for _, y := range rt {
					switch c {
					case '-':
						res = append(res, x-y)
					case '+':
						res = append(res, x+y)
					case '*':
						res = append(res, x*y)
					}
				}
			}
		}
	}

	if len(res) == 0 {
		num, _ := strconv.Atoi(input)
		res = append(res, num)
	}

	return res
}
