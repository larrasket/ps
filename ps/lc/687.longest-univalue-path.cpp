/*
 * Problem: https://leetcode.com/problems/longest-univalue-path/
 * Tags: Path of tree
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
int mx;
class Solution {
  int high(TreeNode *root, int &i) {
    if (!root || root->val != i)
      return 0;
    int r = high(root->left, root->val), l = high(root->left, root->val),
        x = r + l;
    mx = x > mx ? x : mx;
    return 1 + x;
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int i = 9999;
    high(root, i);
    return mx;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
