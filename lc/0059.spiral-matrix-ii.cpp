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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
class Solution {
  int max;
  // 0 right
  // 1 down
  // 2 left
  // 3 up
  // TODO HANDLE NOT OUT POUND
  void solve(vector<vector<int>> &ans, int i, int j, int n, int pos) {
    if (0 > i || 0 > j || i >= max || j >= max || ans[i][j])
      return;
    bool outpound = 1;
    switch (pos) {
    case 0:
      for (; j < max; j++) {
        if (ans[i][j]) {
          outpound = 0;
          break;
        }
        ans[i][j] = ++n;
      }
      solve(ans, i + 1, j - 1, n, 1);
      break;
    case 1:
      for (; i < max; i++) {
        if (ans[i][j]) {
          outpound = 0;
          break;
        }
        ans[i][j] = ++n;
      }
      solve(ans, i - 1, j - 1, n, 2);
      break;
    case 2:
      for (; j >= 0; j--) {
        if (ans[i][j]) {
          outpound = 0;
          break;
        }
        ans[i][j] = ++n;
      }
      solve(ans, i - 1, j + 1, n, 3);
      break;
    case 3:
      for (; i >= 0; i--) {
        if (ans[i][j]) {
          break;
        }
        ans[i][j] = ++n;
      }
      solve(ans, i + 1, j + 1, n, 0);
      break;
    }
  }

public:
  vector<vector<int>> generateMatrix(int n) {
    max = n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    solve(ans, 0, 0, 0, 0);
    return ans;
  }
};
