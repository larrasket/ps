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
  unordered_map<int, vector<int>> v; // adjacency list
  int ans;

  void cg(TreeNode *root, int p = -1) {
    if (!root)
      return;
    int val = root->val;
    if (p != -1) {
      v[p].push_back(val);
      v[val].push_back(p);
    }
    cg(root->left, val);
    cg(root->right, val);
  }

public:
  int amountOfTime(TreeNode *root, int start) {
    cg(root);
    queue<int> q;
    q.push(start);
    unordered_map<int, bool> s;
    s[start] = 1;
    while (!q.empty()) {
      int n = q.size();
      ans++;
      while (n--) {
        auto f = q.front();
        q.pop();
        for (auto &i : v[f]) {
          if (!s[i]) {
            q.push(i);
            s[i] = 1;
          }
        }
      }
    }
    return ans - 1;
  }
};
