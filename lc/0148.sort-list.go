package lc

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	tmpnode := head
	lst := make([]*ListNode, 0)
	for tmpnode != nil {
		lst = append(lst, tmpnode)
		tmpnode = tmpnode.Next
	}
	end := len(lst)
	lst = *MergeSort(&lst)
	for i := 1; i < end; i++ {
		lst[i-1].Next = lst[i]
	}
	lst[end-1].Next = nil
	return lst[0]
}

func MergeSort(listNode *[]*ListNode) *[]*ListNode {
	if len(*listNode) < 2 {
		return listNode
	}
	mid := len(*listNode) / 2
	l := (*listNode)[:mid]
	r := (*listNode)[mid:]
	return Merge(MergeSort(&l), MergeSort(&r))
}

func Merge(left, right *[]*ListNode) *[]*ListNode {
	na, nb, sz, j, i := len(*left), len(*right), len(*left)+len(*right), 0, 0
	res := make([]*ListNode, sz)
	for i < na && j < nb {
		if (*left)[i].Val > (*right)[j].Val {
			res = append(res, (*right)[j])
			j++
		} else {
			res = append(res, (*left)[i])
			i++
		}
	}
	for i < na {
		res = append(res, (*left)[i])
		i++
	}
	for j < nb {
		res = append(res, (*right)[j])
		j++
	}
	return &res
}
