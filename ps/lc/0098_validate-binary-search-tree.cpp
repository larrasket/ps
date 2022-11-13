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
  int last;
  bool res = 1, first = 1;
  void inorde(TreeNode *root) {
    if (!root || !res)
      return;
    inorde(root->left);
    if (root->val <= last && !first) {
      res = false;
      first = 0;
      return;
    }
    first = 0;
    last = root->val;
    inorde(root->right);
  }

public:
  bool isValidBST(TreeNode *root) {
    auto t = root;
    while (t) {
      last = t->val;
      t = t->left;
    }
    inorde(root);
    return res;
  }
};
