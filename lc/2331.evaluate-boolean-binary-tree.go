package lc

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func evaluateTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Val == 0 {
		return false
	} else if root.Val == 1 {
		return true
	}

	var l bool
	var r bool
	if root.Left != nil {
		switch root.Left.Val {
		case 0:
			l = false
		case 1:
			l = true
		default:
			l = evaluateTree(root.Left)
		}
	}

	if root.Right != nil {
		switch root.Right.Val {
		case 0:
			r = false
		case 1:
			r = true
		default:
			r = evaluateTree(root.Right)
		}
	}

	if root.Val == 2 {
		return r || l
	}
	return r && l

}
