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
class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root)
      if (key < root->val)
        root->left = deleteNode(root->left, key);
      else if (key > root->val)
        root->right = deleteNode(root->right, key);
      else {
        if (!root->left && !root->right)
          return NULL;
        if (!root->left || !root->right)
          return root->left ? root->left : root->right;

        TreeNode *temp = root->left;
        while (temp->right != NULL)
          temp = temp->right;
        root->val = temp->val;
        root->left = deleteNode(root->left, temp->val);
      }
    return root;
  }
};
