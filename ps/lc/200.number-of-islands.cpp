/*
 * Problem: https://leetcode.com/problems/number-of-islands/
 * Tags: Array
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
class Solution {
  int m;
  int n;

public:
  void checkpos(vector<vector<char>> &gird, const int &mx, const int &nx) {
    if ((nx >= n || nx < 0) || (mx >= m || mx < 0) || gird[mx][nx] == '0')
      return;
    gird[mx][nx] = '0';
    checkpos(gird, mx, nx + 1);  // right
    checkpos(gird, mx, nx - 1);  // left
    checkpos(gird, mx + 1, nx);  // up
    checkpos(gird, mx + -1, nx); // down
  }
  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1')
          ans++, checkpos(grid, i, j);
      }
    }
    return ans;
  }
};
