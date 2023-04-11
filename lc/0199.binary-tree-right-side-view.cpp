/*
 * Problem:
 * Tags:
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

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    vector<int> ans;
    if (!root)
      return ans;
    q.push(root);
    while (!q.empty()) {
      int s = q.size();
      TreeNode *lastNotNullNode;
      for (int i = 0; i < s; i++) {
        lastNotNullNode = q.front();
        q.pop();
        if (lastNotNullNode->left != nullptr)
          q.emplace(lastNotNullNode->left);
        if (lastNotNullNode->right != nullptr)
          q.emplace(lastNotNullNode->right);
      }
      ans.push_back(lastNotNullNode->val);
    }
    return ans;
  }
};
