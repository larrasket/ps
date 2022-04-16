/*
 * Problem: https://leetcode.com/problems/create-binary-tree-from-descriptions/
 * Tags: DFS
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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> getNode; // to check if node alredy exist
    unordered_map<int, bool> isChild; // to check if node has parent or not
    for (auto &v : descriptions) {
      if (getNode.count(v[0]) == 0) {
        TreeNode *par = new TreeNode(v[0]);
        getNode[v[0]] = par;
      }
      if (getNode.count(v[1]) == 0) {
        TreeNode *child = new TreeNode(v[1]);
        getNode[v[1]] = child;
      }
      if (v[2] == 1)
        getNode[v[0]]->left = getNode[v[1]]; // left-child
      else
        getNode[v[0]]->right = getNode[v[1]]; // right-child
      isChild[v[1]] = true;
    }
    TreeNode *ans = NULL;
    for (auto &v : descriptions) {
      if (isChild[v[0]] !=
          true) { // if node has no parent then this is root node
        ans = getNode[v[0]];
        break;
      }
    }
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
