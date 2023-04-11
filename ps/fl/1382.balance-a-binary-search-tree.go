package lc

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hight(treeNode *TreeNode) int {
	if treeNode == nil {
		return 0
	}
	lh := hight(treeNode.Left)
	rh := hight(treeNode.Right)
	return int(math.Max(float64(lh), float64(rh))) + 1
}

func balanceBST(root *TreeNode) *TreeNode {

	df := func(root *TreeNode) (bf int) {
		return hight(root.Left) - hight(root.Right)
	}

	return root
}
