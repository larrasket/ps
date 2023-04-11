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
  map<int, int> mp;
  void slv(TreeNode *root) {
    if (!root)
      return;
    mp[root->val]++;
    slv(root->right);
    slv(root->left);
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> ans;
    slv(root1);
    slv(root2);
    for (auto &i : mp) {
      while (i.second) {
        ans.push_back(i.first);
        i.second--;
      }
    }
    return ans;
  }
};
