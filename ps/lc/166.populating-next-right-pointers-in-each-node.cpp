/*
 * Problem:
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Tags: pointer
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
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        Node *x = q.front();
        q.pop();
        if (i != n - 1)
          x->next = q.front();
        if (x->left)
          q.push(x->left);
        if (x->right)
          q.push(x->right);
      }
    }
    return root;
  }
};
