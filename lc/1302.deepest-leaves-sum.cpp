/*
 * Problem: 1302. Deepest Leaves Sum
 * Tags: https://leetcode.com/problems/deepest-leaves-sum/
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
int sum;
void slv(TreeNode *root) {}
int deepestLeavesSum(TreeNode *root) {
  queue<TreeNode *> l;
  l.push(root);
  int sum, n;
  while (!l.empty()) {
    sum = 0, n = l.size();
    for (int i = 0; i < n; i++) {
      auto k = l.front();
      l.pop();
      sum += k->val;
      if (k->left)
        l.push(k->left);
      if (k->right)
        l.push(k->right);
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
