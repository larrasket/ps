/*
 * Problem: https://www.lintcode.com/problem/1704/
 * Tags: DFS
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
#include <streambuf>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   * @param root: the root node
   * @param L: an integer
   * @param R: an integer
   * @return: the sum
   */
  int l, r, ans;
  void bst(TreeNode *root) {
    if (!root)
      return;
    if (root->val < l) {
      bst(root->right);
      return;
    } else if (root->val > r) {
      bst(root->left);
      return;
    }
    ans += root->val;
    bst(root->left);
    bst(root->right);
  }
  int rangeSumBST(TreeNode *root, int L, int R) {
    ans = 0, l = L, r = R;
    bst(root);
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
