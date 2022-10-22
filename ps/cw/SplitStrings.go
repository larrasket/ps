package kata

func Solution(str string) []string {
	var res []string
	if len(str)%2 != 0 {
		str += "_"
	}
	for i := 0; i < len(str); i += 2 {
		res = append(res, str[i:i+2])
	}
	return res
}
