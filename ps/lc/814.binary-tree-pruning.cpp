/*
 * Problem: https://leetcode.com/problems/binary-tree-pruning/
 * Tags: BST
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
  int ic;
  int acc(TreeNode *root, TreeNode *p, bool d = 0) {
    if (!root)
      return 0;
    ic = root->val + acc(root->left, root, 0) + acc(root->right, root, 1);
    if (!ic) {
      if (d)
        p->right = nullptr;
      else
        p->left = nullptr;
      return 0;
    } else {
      return root->val;
    }
  }

public:
  TreeNode *pruneTree(TreeNode *root) {
    if (!root)
      return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && root->val == 0)
      return NULL;
    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
