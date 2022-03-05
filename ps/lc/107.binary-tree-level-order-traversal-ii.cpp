/*
 * Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> ans;
  queue<TreeNode *> q;
  int n;
  if (!root)
    return ans;
  q.push(root);
  while (!q.empty()) {
    n = q.size();
    vector<int> m;
    for (int i = 0; i < n; i++) {
      auto t = q.front();
      m.push_back(t->val);
      q.pop();
      if (t->left)
        q.push(t->left);
      if (t->right)
        q.push(t->right);
    }
    ans.push_back(m);
  }
  reverse(begend(ans));
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
