
/*
 * Problem: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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

int pairSum(ListNode *head) {
  int max = 0;
  vector<ListNode *> tempstack;
  auto temphead = head;
  while (temphead) {
    tempstack.push_back(temphead);
    temphead = temphead->next;
  }
  int i = tempstack.size() - 1;
  int n = tempstack.size() / 2;
  while (i >= n) {
    int sum = tempstack[i]->val + head->val;
    max = (sum > max) ? sum : max;
    head = head->next;
    i--;
  }
  return max;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
