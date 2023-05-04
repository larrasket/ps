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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct comp {
  bool operator()(ListNode *a, ListNode *b) { return (a->val > b->val); }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if (!n)
      return nullptr;
    priority_queue<ListNode *, vector<ListNode *>, comp> p;
    for (int i = 0; i < n; i++) {
      ListNode *t = lists[i];
      while (t) {
        p.push(t);
        t = t->next;
      }
    }
    if (p.empty()) {
      return nullptr;
    }
    ListNode *rt = p.top(), *t = nullptr;
    ListNode *ans = rt;
    while (!p.empty()) {
      rt->next = p.top();
      rt = rt->next;
      p.pop();
    }
    if (rt)
      rt->next = nullptr;
    return ans;
  }
};
