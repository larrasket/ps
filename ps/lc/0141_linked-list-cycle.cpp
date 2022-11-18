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
//   ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
  bool hasCycle(ListNode *head) {
    std::map<ListNode *, bool> v;
    while (head) {
      if (v[head])
        return 1;
      v[head] = 1;
      head = head->next;
    }
    return 0;
  }
};
