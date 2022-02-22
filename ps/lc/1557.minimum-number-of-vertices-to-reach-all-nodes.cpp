/*
 * Problem:
 * https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * Tags: Graphs
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

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
  vector<int> res, in(n);
  for (auto edge : edges)
    in[edge[1]]++;
  for (int i = 0; i != n; ++i)
    if (in[i] == 0)
      res.push_back(i);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
