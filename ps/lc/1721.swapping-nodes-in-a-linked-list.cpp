/*
 * Problem: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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

ListNode *swapNodes(ListNode *head, int k) {
  int i = 0;
  auto it = head, tail = head, beforetail = head;
  k--;
  for (i = 0; i < k; i++) {
    it = it->next;
  }
  tail = it;
  for (int j = 0; tail->next != nullptr; j++) {
    tail = tail->next;
    beforetail = beforetail->next;
  }
  int t = beforetail->val;
  beforetail->val = it->val;
  it->val = t;
  return head;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 5; i++) {
    cout << i << endl;
  }
}
