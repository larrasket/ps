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
  int islandPerimeter(vector<vector<int>> &grid) {
    int ans(0), mi = grid.size(), mj = grid[0].size();
    for (int i = 0; i < mi; i++) {
      for (int j = 0; j < mj; j++) {
        if (!grid[i][j])
          continue;
        int left = j - 1, right = j + 1, up = i - 1, down = i + 1;
        if (left < 0)
          ans++;
        else if (!grid[i][left])
          ans++;
        if (right >= mj)
          ans++;
        else if (!grid[i][right])
          ans++;
        if (down >= mi)
          ans++;
        else if (!grid[down][j])
          ans++;
        if (up < 0)
          ans++;
        else if (!grid[up][j])
          ans++;
      }
    }
    return ans;
  }
};
