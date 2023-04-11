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
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int ans(0), n(grid.size()), m(grid[0].size());
    int sumr1, sumr2, sumr3, sumc1, sumc2, sumc3, d1, d2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + 2 < n && j + 2 < m) {
          sumr1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
          sumr2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
          if (sumr1 != sumr2)
            continue;
          sumr3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
          if (sumr1 != sumr3)
            continue;
          sumc1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
          if (sumr1 != sumc1)
            continue;
          sumc2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
          if (sumr1 != sumc2)
            continue;
          sumc3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
          if (sumr1 != sumc3)
            continue;
          d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
          if (sumr1 != d1)
            continue;
          d2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
          if (sumr1 != d2)
            continue;
          ans++;
        }
      }
    }
    return ans;
  }
};
