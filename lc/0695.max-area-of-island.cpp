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
  int n, m;
  int tmp;
  int solve(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
            int j) {
    if (i < 0 || i >= n)
      return 0;

    if (j < 0 || j >= m)
      return 0;
    if (visited[i][j] || !grid[i][j])
      return 0;
    visited[i][j] = 1;
    tmp++;
    solve(grid, visited, i + 1, j);
    solve(grid, visited, i - 1, j);
    solve(grid, visited, i, j + 1);
    solve(grid, visited, i, j - 1);
    return tmp;
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans(0);
    n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] && !visited[i][j]) {
          tmp = 0;
          ans = max(ans, solve(grid, visited, i, j));
        }
      }
    }
    return ans;
  }
};
