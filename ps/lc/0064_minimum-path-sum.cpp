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
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 1; i < m; i++) {
      grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j != 0)
          grid[i][j] += min({grid[i - 1][j], grid[i][j - 1]});
        else
          grid[i][j] += grid[i - 1][j];
      }
    }
    return grid[n - 1][m - 1];
  }
};
