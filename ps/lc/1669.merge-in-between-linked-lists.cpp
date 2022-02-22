/*
 * Problem: https://leetcode.com/problems/merge-in-between-linked-lists/
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
ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
  ListNode *f = list1, *s = list1;
  for (int i = 0; i < a - 1; i++)
    f = f->next;

  s = f;
  for (int i = a - 1; i < b; i++)
    s = s->next;
  f->next = list2;
  while (list2->next != NULL)
    list2 = list2->next;
  list2->next = s->next;
  return list1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
