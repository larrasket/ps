/*
 * Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Tags: Array
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto &c : nums) {
      minHeap.push(c);
      if (minHeap.size() > k)
        minHeap.pop();
    }
    return minHeap.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
