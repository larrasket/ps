package lc

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumEvenGrandparent(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var s int
	if root.Val%2 == 0 {
		if root.Left != nil {

			if root.Left.Left != nil {
				s += root.Left.Left.Val
			}

			if root.Left.Right != nil {
				s += root.Left.Right.Val
			}

		}
		if root.Right != nil {
			if root.Right.Left != nil {
				s += root.Right.Left.Val
			}

			if root.Right.Right != nil {
				s += root.Right.Right.Val
			}

		}

	}
	s += sumEvenGrandparent(root.Left) + sumEvenGrandparent(root.Right)
	return s
}
