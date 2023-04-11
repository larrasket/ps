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
  int c;
  vector<int> ans;

public:
  void inorder(TreeNode *root, int n = 0) {
    if (!root || ans.size() >= c)
      return;
    inorder(root->left, n + 1);
    ans.push_back(root->val);
    inorder(root->right, n + 1);
  }
  int kthSmallest(TreeNode *root, int k) {
    c = k;
    inorder(root);
    return ans[k - 1];
  }
};
