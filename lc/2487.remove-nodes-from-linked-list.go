package lc

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNodes(head *ListNode) *ListNode {
	tmp := head.Next
	var stack []*ListNode
	stack = append(stack, head)
	for tmp != nil {
		for len(stack) != 0 && tmp.Val > stack[len(stack)-1].Val {
			stack = stack[0 : len(stack)-1]
		}
		stack = append(stack, tmp)
		tmp = tmp.Next
	}
	for i := 0; i < len(stack)-1; i++ {
		stack[i].Next = stack[i+1]
	}
	stack[len(stack)-1].Next = nil
	return stack[0]
}
