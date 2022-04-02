/*
 * Problem: https://leetcode.com/problems/spiral-matrix/
 * Tags: Array
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class Solution {

  enum { right, down, left, up };
  vector<int> ans{};
  int m, n;
  void solve(vector<vector<int>> &matrix, vector<vector<bool>> hash, int go = 0,
             int mx = 0, int nx = 0) {

    if (mx < 0 || nx < 0 || mx >= m || nx >= n)
      return;
    switch (go) {
    case right:
      for (; nx < n; nx++) {
        if (hash[mx][nx])
          break;
        hash[mx][nx] = 1;
        ans.push_back(matrix[mx][nx]);
      }
      solve(matrix, hash, down, mx + 1, nx - 1);
      break;

    case down:
      for (; mx < m; mx++) {
        if (hash[mx][nx])
          break;
        hash[mx][nx] = 1;
        ans.push_back(matrix[mx][nx]);
      }
      solve(matrix, hash, left, mx - 1, nx - 1);
      break;

    case left:
      for (; nx >= 0; nx--) {
        if (hash[mx][nx])
          break;
        hash[mx][nx] = 1;
        ans.push_back(matrix[mx][nx]);
      }
      solve(matrix, hash, up, mx - 1, nx + 1);
      break;

    case up:
      for (; mx > 0; mx--) {
        if (hash[mx][nx])
          break;
        hash[mx][nx] = 1;
        ans.push_back(matrix[mx][nx]);
      }
      solve(matrix, hash, right, mx - 1, nx + 1);
      break;
    }
  }

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<bool>> hash(n, vector<bool>(m));
    solve(matrix, hash);
    return ans;
  }
};

int main() {
  vector<vector<int>> mv{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution t;
  auto kk = t.spiralOrder(mv);
  for (auto p : kk) {
    cout << p << " ";
  }
}
