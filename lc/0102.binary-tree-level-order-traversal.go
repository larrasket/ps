func levelOrder(root *TreeNode) [][]int {

	q := make([]*TreeNode, 0)
	ans := make([][]int, 0)

	if root == nil {
		return ans
	}

	q = append(q, root)
	l := len(q)
	for l > 0 {

		pans := make([]int, 0)
		ll := len(q)

		for ll > 0 {
			r := q[0]
			q = q[1:]
			pans = append(pans, r.Val)

			if r.Left != nil {
				q = append(q, r.Left)
			}

			if r.Right != nil {
				q = append(q, r.Right)
			}
			ll--

		}
		ans = append(ans, pans)
		l = len(q)

	}
	return ans

}
