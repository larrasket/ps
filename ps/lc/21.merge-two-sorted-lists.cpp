/*
 * Problem: https://leetcode.com/problems/merge-two-sorted-lists/
 * Tags: Linked List
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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode usage(INT_MIN);
  ListNode *head = &usage;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      head->next = list1;
      list1 = list1->next;
    } else {
      head->next = list2;
      list2 = list2->next;
    }
    head = head->next;
  }
  head->next = list1 ? list1 : list2;
  return usage.next;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
