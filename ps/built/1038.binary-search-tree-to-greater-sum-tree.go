package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bstToGst(root *TreeNode) *TreeNode {
	solve(root)
	return root
}

func solve(root *TreeNode) int {
	if root == nil {
		return 0
	}
	root.Val = solve(root.Right) + root.Val + solve(root.Left)
	return root.Val
}
