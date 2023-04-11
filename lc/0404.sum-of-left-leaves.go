package lc

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	return solve(root, false)
}

func solve(root *TreeNode, left bool) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil && left {
		return root.Val
	}
	return solve(root.Left, true) + solve(root.Right, false)
}
