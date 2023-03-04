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
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    // Initialization: all 0 cells are already at distance 0
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
        } else {
          dist[i][j] = INT_MAX;
        }
      }
    }
    // BFS
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int curr_row = curr.first;
      int curr_col = curr.second;
      for (auto &dir : dirs) {
        int new_row = curr_row + dir.first;
        int new_col = curr_col + dir.second;
        if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
          if (dist[new_row][new_col] > dist[curr_row][curr_col] + 1) {
            dist[new_row][new_col] = dist[curr_row][curr_col] + 1;
            q.push({new_row, new_col});
          }
        }
      }
    }
    return dist;
  }
};
