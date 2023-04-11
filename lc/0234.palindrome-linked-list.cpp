/*
 * Problem: https://leetcode.com/problems/palindrome-linked-list/
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
bool isPalindrome(ListNode *head) {
  vector<ListNode *> mylist;
  while (head) {
    mylist.push_back(head);
    head = head->next;
  }
  int s = 0;
  int e = mylist.size();
  while (s <= e) {
    if (mylist[s]->val != mylist[e]->val)
      return false;
    s++, e--;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
