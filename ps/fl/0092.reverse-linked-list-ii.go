package lc

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	// reach pre and first
	curr := head
	var pre, last, tmp *ListNode

	i := 1
	for ; i <= left && curr != nil; i++ {
		pre = curr
		curr = curr.Next
	}
	println(curr.Val)
	start := curr.Next
	prev := curr
	do(start)
	do(prev)
	do(pre)
	do(last)
	do(tmp)

	pre.Next = last
	curr.Next = tmp
	return head
}

func do(interface{}) {}

// for ; i <= right && start != nil; i++ {
// 	last = start
// 	tmp = last.Next
// 	start.Next = prev
// 	prev = last
// 	start = last.Next
// }
