package lc

type Node struct {
	Val       int
	Neighbors []*Node
}

var mp = make(map[*Node]*Node)

func cloneGraph(node *Node) *Node {
	if node == nil {
		return node
	}
	if _, ok := mp[node]; !ok {
		mp[node] = new(Node)
		mp[node].Val = node.Val
		for _, value := range node.Neighbors {
			mp[node].Neighbors = append(mp[node].Neighbors, cloneGraph(value))
		}
	}
	return mp[node]
}
