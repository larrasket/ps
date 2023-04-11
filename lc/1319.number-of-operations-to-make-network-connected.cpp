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
  vector<int> parents;

  int redundant = 0;

public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    int sz = connections.size();
    for (int i = 0; i < sz; i++) {
      uni(connections[i][0], connections[i][1]);
    }

    int compontes(0);
    for (int i = 0; i < n; i++) {
      if (parents[i] == i)
        compontes++;
    }
    compontes--; // subtract the main compon
    if (redundant >= compontes) {
      return compontes;
    } else
      return -1;
  }
  int find(int i) {
    while (i != parents[i]) {
      i = parents[i];
    }
    return i;
  }
  void uni(int i, int x) {
    i = find(i), x = find(x);
    if (i != x) {
      parents[x] = i;
      return;
    }
    redundant++;
  }
};
