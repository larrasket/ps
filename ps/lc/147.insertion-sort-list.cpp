/*
 * Problem: https://leetcode.com/problems/insertion-sort-list/
 * Tags: Sorting
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
void swapL(ListNode *first, ListNode second) {}
ListNode *insertionSortList(ListNode *head) {
  ListNode *helper = new ListNode();
  ListNode *pre = helper;
  ListNode *curr = head;
  ListNode *next = nullptr;
  while (curr) {
    next = curr->next;
    while (pre && pre->next->val < curr->val) {
      statements
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
