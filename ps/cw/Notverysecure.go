package kata

func alphanumeric(str string) bool {
	if len(str) == 0 {
		return false
	}
	for _, value := range str {
		if (value < 'a' || value > 'z') && (value < '0' || value > '9') && (value < 'A' ||
			value > 'Z') {
			return false
		}
	}
	return true
}
