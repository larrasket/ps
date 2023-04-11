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
char nth_letter(int n) { return "abcdefghijklmnopqrstuvwxyz"[n - 1]; }

void trv(TreeNode *root, string &ans) {
  if (!root)
    return;
  ans += nth_letter(root->val + 1);
  string l, r;
  trv(root->left, l);
  trv(root->right, r);
  string cl = l, cr = r;
  if (root->left && root->right) {
    reverse(begend(l));
    reverse(begend(r));
  }
  if (l > r)
    ans += cr;
  else
    ans += cl;
}

string smallestFromLeaf(TreeNode *root) {
  string ans;
  trv(root, ans);
  reverse(begend(ans));
  return ans;
}

int main() {}
