/*
 * Problem:
 * Tags:
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
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    map<ListNode *, bool> mp;
    auto hd = head;
    while (hd) {
      if (mp[hd])
        return hd;
      mp[hd] = 1;
      hd = hd->next;
    }
    return nullptr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
