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
  int mz;
  int nz;
  map<pair<int, int>, bool> mp;

public:
  void set(vector<vector<int>> &m, int i, int j) {
    for (int x = 0; x < nz; x++) {
      if (!m[i][x])
        continue;
      m[i][x] = 0;
      mp[{i, x}] = 1;
    }
    for (int x = 0; x < mz; x++) {
      if (!m[x][j])
        continue;
      m[x][j] = 0;
      mp[{x, j}] = 1;
    }
  }
  void setZeroes(vector<vector<int>> &matrix) {
    mz = matrix.size();
    nz = matrix[0].size();
    for (int i = 0; i < mz; i++) {
      for (int j = 0; j < nz; j++) {
        if (!matrix[i][j] && !mp[{i, j}]) {
          set(matrix, i, j);
        }
      }
    }
  }
};
