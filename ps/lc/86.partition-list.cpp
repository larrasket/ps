/*
 * Problem: https://leetcode.com/problems/partition-list/
 * Tags: Two Pointers
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
ListNode *partition(ListNode *head, int x) {
  ListNode *l = new ListNode(), *r = new ListNode();
  ListNode *lt = l, *rt = r;
  while (head != nullptr) {
    if (head->val < x) {
      lt->next = head;
      lt = lt->next;
    } else {
      rt->next = head;
      rt = rt->next;
    }
    head = head->next;
  }
  lt->next = rt->next;
  rt->next = nullptr;
  return lt->next;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
