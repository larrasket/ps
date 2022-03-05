/*
 * Problem: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * Tags: BFS
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
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> ans;
  queue<Node *> q;
  int n = 0;
  q.push(root);
  while (!q.empty()) {
    vector<int> tmp;
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto t = q.front();
      q.front();
      for (auto &i : t->children) {
        tmp.push_back(i->val);
        q.push(i);
      }
    }
    ans.push_back(tmp);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
