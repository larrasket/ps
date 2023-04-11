/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	return solution(&nums, 0, len(nums)-1)
}

func solution(arr *[]int, l, r int) (root *TreeNode) {
	root = new(TreeNode)
	if l > r {
		return nil
	}
	var m int = (l + r) / 2
	root.Val = (*arr)[m]
	root.Left = solution(arr, l, m-1)
	root.Right = solution(arr, m+1, r)
	return
}
