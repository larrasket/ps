package lc

import (
	"container/heap"
	"sort"
)

// I wrote this one before, but it is not efficient enough.
// It uses a map to count frequencies and then sorts the map entries.
// Time complexity is O(n log n) due to sorting.
func topKFrequent_old(nums []int, k int) []int {
	mmm := map[int]int{}
	type dummy struct {
		value int
		key   int
	}
	m := []dummy{}
	ans := make([]int, k)
	for _, value := range nums {
		mmm[value]++
	}
	for key, value := range mmm {
		m = append(m, dummy{value, key})
	}
	sort.Slice(m, func(i, j int) bool { return m[i].value < m[j].value })
	for i := 0; i < k; i++ {
		ans[i] = m[i].key
	}
	return ans
}

type pair struct {
	key   int
	value int
}

type minHeap []pair

func (h minHeap) Len() int { return len(h) }

// Use < for min-heap so least frequent is at top
func (h minHeap) Less(i, j int) bool { return h[i].value < h[j].value }
func (h minHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *minHeap) Push(x interface{}) {
	*h = append(*h, x.(pair))
}

func (h *minHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

// Rename to avoid redeclaration error
func topKFrequentInts(nums []int, k int) []int {
	mmm := map[int]int{}
	for _, value := range nums {
		mmm[value]++
	}
	h := &minHeap{}
	heap.Init(h)
	for key, value := range mmm {
		heap.Push(h, pair{key: key, value: value})
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	// Pop from heap and reverse to get most frequent first
	ans := make([]int, h.Len())
	for i := len(ans) - 1; i >= 0; i-- {
		p := heap.Pop(h).(pair)
		ans[i] = p.key
	}
	return ans
}
