/*
 * Problem:  https://leetcode.com/problems/path-sum/
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
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL)
      return false;
    if (root->val == sum && root->left == NULL && root->right == NULL)
      return true;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
