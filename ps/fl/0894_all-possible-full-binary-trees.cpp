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
  vector<TreeNode *> nd;
  void solve(int n, TreeNode *r, TreeNode *cr) {
    if (!r || !cr) {
      return;
    }
    if (n < 2) {
      return;
    }

    n -= 2;
    cr->left = new TreeNode(0);
    cr->right = new TreeNode(0);

    if (n == 0) {
      TreeNode *nr = new TreeNode(0);
      cpy(r, nr);
      nd.push_back(nr);
      return;
    }
    solve(n, r, cr->left);
    solve(n, r, cr->right);
  }
  void cpy(TreeNode *src, TreeNode *dst) {
    if (!src)
      return;
    if (src->right) {
      dst->right = new TreeNode(0);
      cpy(src->right, dst->right);
    }
    if (src->left) {
      dst->left = new TreeNode(0);
      cpy(src->left, dst->left);
    }
  }

public:
  vector<TreeNode *> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return nd;
    TreeNode *root = new TreeNode(0);
    solve(n - 1, root, root);
    return nd;
  }
};
