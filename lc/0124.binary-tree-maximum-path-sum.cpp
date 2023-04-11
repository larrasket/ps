/*
 * Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Tags: Tree
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
class Solution {
  int m;

public:
  int leftsum(TreeNode *root) {
    if (!root)
      return 0;
    return root->val + leftsum(root->left);
  }

  int rightsum(TreeNode *root) {
    if (!root)
      return 0;
    return root->val + rightsum(root->right);
  }
  void dfs(TreeNode *root) {
    if (!root)
      return;
    int x = leftsum(root) + rightsum(root);
    if (x >= m)
      m = x;
    dfs(root->left);
    dfs(root->right);
  }
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return m;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
