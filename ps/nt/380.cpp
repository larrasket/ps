/*
 * Problem: https://www.lintcode.com/problem/380/
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *, bool> m;
    auto hA = headA;
    while (hA) {
      m[hA] = 1;
      hA = hA->next;
    }
    while (headB) {
      if (m[headB])
        return headB;
      headB = headB->next;
    }
    return nullptr;
  }
};
