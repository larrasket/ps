package kata

func ValidParentheses(parens string) bool {
	stack := []rune{}
	for _, value := range parens {
		if value == '(' {
			stack = append(stack, '(')
		} else {
			n := len(stack)
			if n > 0 && stack[n-1] == '(' {
				stack = stack[:n-1]
			} else {
				return false
			}
		}
	}

	return true
}
