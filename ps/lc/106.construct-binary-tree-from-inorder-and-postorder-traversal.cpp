/*
 * Problem:
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    int root = postorder.size() - 1;
    return builder(postorder, inorder, 0, inorder.size() - 1, root);
  }

  TreeNode *builder(vector<int> &post, vector<int> &in, int left, int right,
                    int &root) {
    if (left > right || root < 0) {
      return nullptr;
    }
    int pvt = left;
    while (in[pvt] != post[root])
      pvt++;
    auto rt = new TreeNode(in[pvt]);
    root--;
    rt->left = builder(post, in, left, pvt - 1, root);
    rt->right = builder(post, in, pvt + 1, right, root);
    return rt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
