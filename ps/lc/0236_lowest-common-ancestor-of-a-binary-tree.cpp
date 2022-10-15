#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstddef>
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {

  // vector<TreeNode *> ppath, qpath;
  bool solve(TreeNode *root, TreeNode *p, vector<TreeNode *> &vec) {
    if (!root)
      return false;
    vec.push_back(root);
    if (root == p)
      return true;
    if (solve(root->right, p, vec) || solve(root->left, p, vec))
      return 1;
    vec.pop_back();
    return false;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pathp, pathq;
    solve(root, p, pathp);
    solve(root, q, pathq);

    while (pathp.size() > pathq.size()) {
      pathp.pop_back();
    }
    while (pathp.size() < pathq.size()) {
      pathq.pop_back();
    }
    for (long long i = pathq.size() - 1; i >= 0; i--) {
      if (pathq[i] == pathp[i])
        return pathp[i];
    }
    return nullptr;
  }
};
