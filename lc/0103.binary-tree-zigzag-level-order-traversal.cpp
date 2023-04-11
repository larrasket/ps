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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == NULL) {
      return vector<vector<int>>();
    }
    vector<vector<int>> result;

    queue<TreeNode *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty()) {
      int size = nodesQueue.size();
      vector<int> row(size);
      for (int i = 0; i < size; i++) {
        TreeNode *node = nodesQueue.front();
        nodesQueue.pop();

        // find position to fill node's value
        int index = (leftToRight) ? i : (size - 1 - i);

        row[index] = node->val;
        if (node->left) {
          nodesQueue.push(node->left);
        }
        if (node->right) {
          nodesQueue.push(node->right);
        }
      }
      // after this level
      leftToRight = !leftToRight;
      result.push_back(row);
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
