#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
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
  vector<int> arr;
  TreeNode *balanceBST(TreeNode *root) {
    tv(root);
    cout << arr.size();
    return build(0, arr.size() - 1);
  }
  void tv(TreeNode *root) {
    if (!root)
      return;
    tv(root->left);
    arr.push_back(root->val);
    tv(root->right);
  }
  TreeNode *build(int s, int end) {
    if (s > end) {
      return nullptr;
    }
    int md = (s + end) / 2;
    auto root = new TreeNode(arr[md]);
    root->left = build(s, md - 1);
    root->right = build(md + 1, end);
    return root;
  }
};
