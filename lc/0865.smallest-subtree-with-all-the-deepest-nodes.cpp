#include <iostream>
#include <map>
#include <queue>
#include <vector>
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

  map<TreeNode, bool> deepest;

  int dfs(TreeNode *root) {
    if (!root)
      return -1;
    int left_depth = dfs(root->left);
    int right_depth = dfs(root->right);
    TreeNode *deepest_node =
        left_depth > right_depth ? root->left : root->right;
    deepest[deepest_node->val] = 1;
    if (left_depth == right_depth && right_depth != -1) {
      deepest[root->left->val] = 1;
      deepest[root->right->val] = 1;
    }
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
  }

  TreeNode *bfs(TreeNode *root, TreeNode *p) {
    queue<TreeNode *> a;
    a.push(root);
    while (!a.empty()) {
      TreeNode *tp = a.front();
      a.pop();
      if ((tp->left && deepest[tp->left->val]))
    }
  }

public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    auto troot = root;
    // reach deepest levls
    dfs(root);

    return ans;
  }
};
