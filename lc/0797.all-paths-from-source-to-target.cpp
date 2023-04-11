/*
 * Problem: https://leetcode.com/problems/all-paths-from-source-to-target/
 * Tags: DFS
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

vector<vector<int>> ans;
int n, target;
void solve(vector<vector<int>> graphs, vector<int> way = {}, int index = 0) {
  way.push_back(index);
  if (index == target)
    ans.push_back(way);
  else {
    for (int node : graphs[index]) {
      solve(graphs, way, node);
    }
  }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
