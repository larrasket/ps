/*
 * Problem:
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
#include <utility>
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
  map<int, vector<int>> m;
  void tr(TreeNode *root, int p = 0) {
    if (!root)
      return;
    m[p].push_back(root->val);
    tr(root->left, p - 1);
    tr(root->right, p + 1);
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    tr(root);
    vector<vector<int>> ans;
    for (auto &x : m) {
      ans.push_back(x.second);
    }
    return ans;
  }
};
