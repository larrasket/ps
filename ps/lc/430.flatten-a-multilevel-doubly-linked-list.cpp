/*
 * Problem:
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/ Tags:
 * Linked-List
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
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
  Node *prevnode;
  void helper(Node *head, Node *prevnext) {
    while (head) {
      if (head->child) {
        auto tmp = head->next;
        head->next = head->child;
        head->child->prev = head;
        helper(head->child, tmp);
        head->child = nullptr;
      }
      if (head->next)
        head = head->next;
      else
        break;
    }
    if (prevnext) {
      prevnext->prev = head;
      head->next = prevnext;
    }
  }

public:
  Node *flatten(Node *head) {
    auto tmp = head;
    helper(tmp, nullptr);
    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
