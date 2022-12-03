// package lc

import "math"

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return int(math.Max(float64(maxDepth(root.Right)+1), float64(maxDepth(root.Left)+1)))
}
