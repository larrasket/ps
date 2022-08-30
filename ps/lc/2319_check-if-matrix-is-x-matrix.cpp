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
  bool checkXMatrix(vector<vector<int>> &grid) {
    int ni = grid.size(), nj = grid[0].size();
    for (int i = 0; i < ni; i++) {
      for (int j = 0; j < nj; j++) {
        if ((i + j == ni - 1 || i == j)) {
          if (grid[i][j] == 0)
            return false;
        } else if (grid[i][j] != 0) { // not dig
          return false;
        }
      }
    }
    return true;
  }
};
