/*
 * Problem: https://leetcode.com/problems/path-sum-ii/
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
  vector<vector<int>> ans;

public:
  void slv(TreeNode *root, int sum, vector<int> path = {}) {
    if (!root)
      return;
    path.push_back(root->val);
    if (root->val == sum && !root->left && !root->right)
      ans.push_back(path);
    slv(root->left, sum - root->val, path);
    slv(root->right, sum - root->val, path);
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    slv(root, targetSum);
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
