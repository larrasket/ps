package lc

func findOrder(numCourses int, prerequisites [][]int) []int {
	adj := make([][]int, numCourses)
	dgs := make([]int, numCourses)
	ans := []int{}
	flg := 0
	q := []int{}
	for _, value := range prerequisites {
		adj[value[1]] = append(adj[value[1]], value[0])
		dgs[value[0]]++
	}
	for key, value := range dgs {
		if value == 0 {
			q = append(q, key)
		}
	}
	for len(q) != 0 {
		flg++
		cur := q[0]
		q = q[1:]
		ans = append(ans, cur)
		for _, value := range adj[cur] {
			dgs[value]--
			if dgs[value] == 0 {
				q = append(q, value)
			}
		}
	}
	if flg != numCourses {
		return []int{}
	}
	return ans
}
