/*
 * Problem: https://leetcode.com/problems/number-of-provinces/
 * Tags: Graph
 */

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

void dfs(vector<vector<int>> g, vector<bool> v, int index = 0) {
  v[index] = 1;
  for (int i = 0; i < g.size(); i++) {
    if (!v[i])
      dfs(g, v, i);
  }
}

int findCircleNum(vector<vector<int>> &isConnected) {
  int ans = 1;
  vector<bool> v(isConnected.size());
  dfs(isConnected, vector<bool> v)
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
