/*
 * Problem: https://leetcode.com/problems/next-greater-node-in-linked-list/
 * Tags: Monotonic Stack
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    stack<int> mystack;
    vector<int> ans;
    for (int i = 0; head; i++) {
      ans.push_back(head->val);
      while (!mystack.empty() && ans[mystack.top()] < ans[i])
        ans[mystack.top()] = ans[i], mystack.pop();
      mystack.push(i);
      head = head->next;
    }
    while (!mystack.empty())
      ans[mystack.top()] = 0, mystack.pop();
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
