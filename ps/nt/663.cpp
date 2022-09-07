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
#define INF 2147483647
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

class Solution {
public:
  /**
   * @param rooms: m x n 2D grid
   * @return: nothing
   */
  int m, n;

  void solve(vector<vector<int>> &mp, int i, int j, int distance) {
    if (i >= m || j >= n || i < 0 || j < 0)
      return;
    if (mp[i][j] < distance || distance == 0) {
      mp[i][j] = distance;
      solve(mp, i + 1, j, distance + 1);
      solve(mp, i, j + 1, distance + 1);
      solve(mp, i - 1, j, distance + 1);
      solve(mp, i, j - 1, distance + 1);
    }
  }
  void wallsAndGates(vector<vector<int>> &rooms) {
    m = rooms.size(), n = rooms[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (rooms[i][j] == 0)
          solve(rooms, i, j, 0);
      }
    }
  }
};
