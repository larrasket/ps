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

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
bool comp(ListNode *l, ListNode *y) { return l->val < y->val; }

// NOT SOLVED!!!!!!!1
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    // priority_queue<ListNode *, vector<ListNode *>, decltype(&comp)> pq(comp);
    vector<ListNode *> pq;
    for (auto &i : lists) {
      auto head = i;
      while (head) {
        // pq.push(head);
        // pq.push(head);
        head = head->next;
      }
    }
    ListNode *tmp = pq.top();
    pq.pop();
    auto ans = tmp;
    while (!pq.empty()) {
      tmp->next = pq.top();
      pq.pop();
      tmp = tmp->next;
    }
    return ans;
  }
};
