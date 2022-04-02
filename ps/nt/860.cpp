/*
 * Problem: 860 · Number of Distinct Islands
 * Tags:  array
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
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class Solution {
public:
  /**
   * @param grid: a list of lists of integers
   * @return: return an integer, denote the number of distinct islands
   */

  int m;
  int n;
  enum { ymn, shmal, fok, tht };
  void checkpos(vector<vector<int>> &gird, const int &mx, const int &nx,
                string track, string &tpath) {
    if ((nx >= n || nx < 0) || (mx >= m || mx < 0) || gird[mx][nx] == 0) {
      tpath.append("out");
      return;
    }
    gird[mx][nx] = 0;
    tpath.append(track);
    checkpos(gird, mx, nx + 1, "right", tpath); // right
    checkpos(gird, mx, nx - 1, "left", tpath);  // left
    checkpos(gird, mx + 1, nx, "up", tpath);    // up
    checkpos(gird, mx + -1, nx, "down", tpath); // down
  }
  int numberofDistinctIslands(vector<vector<int>> &grid) {
    unordered_set<string> o;
    int ans = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          string s;
          checkpos(grid, i, j, "x", s);
          o.emplace(s);
        }
      }
    }
    return o.size();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
