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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };
class Solution {
  int v, d;
  void solve(TreeNode *root, int c = 1) {
    if (!root)
      return;
    if (c + 1 == d) {
      auto tl = root->left;
      auto tr = root->right;
      root->left = new TreeNode(v);
      root->right = new TreeNode(v);
      root->left->left = tl;
      root->right->right = tr;
      return;
    }
    solve(root->left, c + 1);
    solve(root->right, c + 1);
  }

public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    v = val, d = depth;
    if (depth == 1) {
      auto tmp = root;
      root = new TreeNode(v);
      root->left = tmp;
      return root;
    }
    solve(root);
    return root;
  }
};
