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
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

class Solution {

  void rot(vector<vector<int>> &grid, int i, int j, int &frsh,
           queue<pair<int, int>> &q) {
    if (i >= n || i < 0)
      return;
    if (j >= m || j < 0)
      return;
    if (grid[i][j] == 1) {
      grid[i][j] = 2;
      q.push({i, j});
      frsh--;
      return;
    }
    return;
  }

  int n;
  int m;

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int ans(0), frsh(0);
    n = grid.size();
    m = grid[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          frsh++;
        }
      }
    }
    while (!q.empty() && frsh) {
      int sz = q.size();
      while (sz) {
        auto front = q.front();
        q.pop();
        rot(grid, front.first + 1, front.second, frsh, q);
        rot(grid, front.first - 1, front.second, frsh, q);
        rot(grid, front.first, front.second + 1, frsh, q);
        rot(grid, front.first, front.second - 1, frsh, q);
        sz--;
      }
      ans++;
    }
    for (auto &i : grid)
      for (auto &j : i)
        if (j == 1)
          return -1;
    return ans;
  }
};
