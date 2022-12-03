package lc

func deleteNode(node *ListNode) {
	prev := node
	node = node.Next
	for {
		prev.Val = node.Val
		node = node.Next
		if node == nil {
			prev.Next = nil
			break
		}
		prev = prev.Next
	}
	prev.Next = nil

}
