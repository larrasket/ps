/*
 * Problem:
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Tags: Tree
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *ans;
void sl(TreeNode *root, int &i, int &p) {
  if (!root)
    return;
  if (root->val >)
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
