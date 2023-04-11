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
map<int, bool> visited;
class Solution {
private:
  void dfs(vector<vector<int>> &edg, int &cnt) {}

public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    int ans = 0;
    for (auto &i : restricted) {
      visited[i] = 1;
    }
    for (auto &i : edges) {
    }
    return ans;
  }
};
