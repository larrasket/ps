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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> nodes;
    traverse(root, 0, 0, nodes);
    vector<vector<int>> ans;
    for (auto p : nodes) {
      vector<int> col;
      for (auto q : p.second) {
        col.insert(col.end(), q.second.begin(), q.second.end());
      }
      ans.push_back(col);
    }
    return ans;
  }

private:
  void traverse(TreeNode *root, int x, int y,
                map<int, map<int, multiset<int>>> &nodes) {
    if (root) {
      nodes[x][y].insert(root->val);
      traverse(root->left, x - 1, y + 1, nodes);
      traverse(root->right, x + 1, y + 1, nodes);
    }
  }
};
