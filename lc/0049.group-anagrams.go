package lc

func groupAnagrams(strs []string) [][]string {
	mp := map[int][]string{}
	ans := map[string][]string{}
	for _, str := range strs {
		mp[len(str)] = append(mp[len(str)], str)
	}
	for _, sl := range mp {
		for _, s := range sl {
			count := [26]byte{}
			for i := range s {
				count[s[i]-'a']++
			}
			key := string(count[:])
			ans[key] = append(ans[key], s)
		}
	}
	res := [][]string{}
	for _, group := range ans {
		res = append(res, group)
	}
	return res
}
