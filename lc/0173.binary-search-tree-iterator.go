// package lc

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

type BSTIterator struct {
}

var curr int
var c chan int

func Constructor(root *TreeNode) BSTIterator {
	n := BSTIterator{}
	c = make(chan int)
	go func() {
		defer func() {
			c <- -1
		}()
		trv(root, c)
	}()
	curr = <-c
	return n
}
func trv(root *TreeNode, c chan int) {
	if root == nil {
		return
	}
	trv(root.Left, c)
	c <- root.Val
	trv(root.Right, c)
}

func (this *BSTIterator) Next() int {
	tmp := curr
	curr = <-c
	return tmp
}

func (this *BSTIterator) HasNext() bool {
	return curr != -1
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
