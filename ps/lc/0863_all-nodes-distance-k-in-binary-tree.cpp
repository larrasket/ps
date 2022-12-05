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
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
  bool GetParents(TreeNode *root, TreeNode *target, vector<TreeNode *> &p) {
    if (!root)
      return 0;
    p.push_back(root);
    if (root == target) {
      p.pop_back();
      return 1;
    }
    if (GetParents(root->left, target, p) || GetParents(root->right, target, p))
      return 1;
    p.pop_back();
    return false;
  }

  map<TreeNode *, bool> v;
  void childs(int k, TreeNode *root, vector<int> &ans, int c = 0) {
    if (!root || v[root])
      return;
    v[root] = 1;
    if (c == k) {
      ans.push_back(root->val);
      return;
    }
    childs(k, root->left, ans, c + 1);
    childs(k, root->right, ans, c + 1);
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<int> ans;
    vector<TreeNode *> prnts;
    GetParents(root, target, prnts);
    childs(k, target, ans);
    int i = prnts.size() - 1;
    int c = 1;
    while (i >= 0) {
      if (c > k)
        break;
      childs(k, prnts[i], ans, c);
      i--;
      c++;
    }
    return ans;
  }
};
