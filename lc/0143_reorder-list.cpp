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

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
  void reorderList(ListNode *head) {
    vector<ListNode *> l;
    auto th = head;
    while (th) {
      l.push_back(th);
      th = th->next;
    }
    th = head;
    int st = 1, et = l.size() - 1, n = l.size(), dum = 1;
    for (int i = 0; i < n && th; i++) {
      if (dum) {
        auto tmp = l[et];
        th->next = tmp;
        th = tmp;
        et--;
      } else {

        auto tmp = l[st];
        th->next = tmp;
        th = tmp;
        st++;
      }
      dum = !dum;
    }
  }
};
