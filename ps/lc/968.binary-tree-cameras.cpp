/*
 * Problem: https://leetcode.com/problems/binary-tree-cameras/
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
#define NO_CAMERA 0
#define HAS_CAMERA 2
#define NOT_NEEDED 1
  int ans = 0;
  int dfs(TreeNode *root) {
    if (!root)
      return NOT_NEEDED;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if (l == NO_CAMERA || r == NO_CAMERA) {
      ans++;
      return HAS_CAMERA;
    } else if (l == HAS_CAMERA || r == HAS_CAMERA) {
      return NOT_NEEDED;
    } else {
      return NO_CAMERA;
    }
  }
  int minCameraCover(TreeNode *root) {
    if (dfs(root) == NO_CAMERA)
      ans++;
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
