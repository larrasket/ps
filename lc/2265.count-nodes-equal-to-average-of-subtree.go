package lc

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ans int

func solve(root *TreeNode) (sum, cnt int) {
	if root == nil {
		return
	}
	lsum, lcnt := solve(root.Left)
	rsum, rcnt := solve(root.Right)
	sum = lsum + rsum + root.Val
	cnt = lcnt + rcnt + 1
	if root.Val == sum/cnt {
		ans++
	}
	return

}

func averageOfSubtree(root *TreeNode) int {
	ans = 0
	solve(root)
	return ans
}
