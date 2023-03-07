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
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    vector<double> dist(n, INT_MIN);
    // build list
    vector<vector<pair<double, int>>> adj(n, vector<pair<double, int>>());
    int ctr = 0;
    for (auto &i : edges) {
      adj[i[0]].push_back({succProb[ctr], i[1]});
      adj[i[1]].push_back({succProb[ctr], i[0]});
      ctr++;
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   less<pair<double, int>>>
        q;
    q.push({1, start});
    dist[start] = 1;
    while (!q.empty()) {
      auto tp = q.top();
      q.pop();
      if (tp.first < dist[tp.second])
        continue;
      for (auto &i : adj[tp.second]) {
        int nd = i.second;
        double w = i.first * tp.first;
        if (dist[nd] < w) {
          dist[nd] = w;
          q.push({w, nd});
        }
      }
    }
    return dist[end] == INT_MIN ? 0 : dist[end];
  }
};
