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
  vector<int> parent;
  int ans; // all compontes

public:
  int removeStones(vector<vector<int>> &stones) {
    int n(stones.size());
    parent.resize(n);
    ans = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
      uni(stones[i][0], stones[i][1]);
    }
    return n - ans;
  }
  int find(int i) {
    while (i != parent[i]) {
      i = parent[i];
    }
    return parent[i];
  }
  void uni(int x, int y) {
    x = find(x), y = find(y);
    if (y != x)
      parent[y] = x, ans--;
  }
};
