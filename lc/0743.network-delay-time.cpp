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
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // build list
    unordered_map<int, vector<pair<int, int>>> mp;
    int ans(-1);
    for (auto &i : times) {
      mp[i[0]].push_back({i[2], i[1]});
    }
    // q
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    q.push({0, k});
    while (!q.empty()) {
      auto tp = q.top();
      q.pop();
      if (tp.first > dist[tp.second])
        continue;
      for (auto &i : mp[tp.second]) {
        int node = i.second, nw = i.first + tp.first;
        if (nw < dist[node]) {
          dist[node] = nw;
          q.push({nw, node});
        }
      }
    }

    for (int i = 1; i < dist.size(); ++i)
      if (dist[i] != INT_MAX) {
        if (dist[i] > ans)
          ans = dist[i];
      } else
        return -1;
    return ans;
  }
};
