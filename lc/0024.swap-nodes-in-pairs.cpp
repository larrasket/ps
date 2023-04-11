/*
 * Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
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

ListNode *swapPairs(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *prev = nullptr;
  ListNode *curr = head;
  ListNode *nxt = head->next;

  head = head->next;

  while (curr && nxt) {
    if (prev)
      prev->next = nxt;
    curr->next = nxt->next;
    nxt->next = curr;
    prev = curr;
    curr = curr->next;
    if (curr)
      nxt = curr->next;
  }

  return head;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
