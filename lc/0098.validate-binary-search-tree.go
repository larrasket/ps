/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	return helper(root, root.Val)
}

func helper(root *TreeNode, mxRoot int) bool {
	if root == nil {
		return true
	}

	var lft, right *int
	if root.Left != nil {
		lft = &root.Left.Val
		if *lft > mxRoot {
			return false
		}
	}

	if root.Right != nil {
		right = &root.Right.Val
		if *right > mxRoot {
			return false
		}
	}

	if lft != nil && *lft >= root.Val {
		return false
	}

	if right != nil && *right <= root.Val {
		return false
	}

	return helper(root.Left) && helper(root.Right)

}
