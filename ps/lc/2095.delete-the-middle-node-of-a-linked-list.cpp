/*
 * Problem: 2095. Delete the Middle Node of a Linked List
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

ListNode *deleteMiddle(ListNode *head) {
  vector<ListNode *> tempvector;
  auto temphead = head;
  while (temphead) {
    tempvector.push_back(temphead);
    temphead = temphead->next;
  }
  if (tempvector.size() == 1)
    return nullptr;
  int todelete = tempvector.size() / 2;
  tempvector[todelete - 1]->next = tempvector[todelete]->next;
  delete tempvector[todelete];
  return head;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
