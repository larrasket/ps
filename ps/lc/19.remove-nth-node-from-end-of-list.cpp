/*
 * Problem: Remove Nth Node From End of List
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
ListNode *removeNthFromEnd(ListNode *head, int n) {
  vector<ListNode *> stacker;
  auto temp = head;
  while (temp != nullptr) {
    stacker.push_back(temp);
    temp = temp->next;
  }

  int toDelete = stacker.size() - n;
  if (stacker[toDelete] == head) {
    head = head->next;
    delete stacker[toDelete];
    return head;
  } else if (stacker[toDelete] == stacker[stacker.size() - 1]) {
    stacker[stacker.size() - 2]->next = nullptr;
    delete stacker[toDelete];
    return head;
  } else {
    delete stacker[toDelete];
    stacker[toDelete - 1]->next =
        (stacker.size() > 2) ? stacker[toDelete + 1] : nullptr;
    return head;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
