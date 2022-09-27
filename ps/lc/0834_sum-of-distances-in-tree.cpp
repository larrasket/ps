#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
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

class Solution {

  priority_queue<pi, vector<pi>, greater<pi>> pq;

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<map<int, bool>> mtrx(n);
    vector<int> ans(n);
    map<pair<int, int>, int> dis;
    int orginl = 0;
    std::function<int(int, int)> fun;
    fun = [&](int i, int j, int ths = 0) -> int {
      if (i == j)
        return 0;
      if (dis[{i, j}] != 0) {
        return dis[{i, j}];
      }
      for (auto &mt : mtrx[i]) {
        if (mt.second) {
          dis[{orginl, mt.first}] = ths + 1;
          dis[{mt.first, orginl}] = ths + 1;
          // return fun(mt.first, j, ths+1);
        }
      }
    };
    for (auto &i : edges) {
      mtrx[i[0]][i[1]] = 1;
      mtrx[i[1]][i[0]] = 1;
    }
    // cal dis
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
      }
    }
    return ans;
  }
};
