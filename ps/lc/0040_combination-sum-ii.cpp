/*
 * Problem:
 * Tags:
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

map<vector<int>, bool> mymap;

void solve(vector<int> &input, int &target, vector<vector<int>> &ans, int n,
           int index = 0, int curr = 0, vector<int> kurrent = {}) {
  if (curr > target)
    return;
  if (curr == target) {
    ans.push_back(kurrent);
    return;
  }
  for (int i = index; i < n; i++) {
    vector<int> temp = kurrent;
    temp.push_back(input[i]);
    solve(input, target, ans, n, i, curr + input[i], temp);
  }
}

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    solve(candidates, target, ans, candidates.size());
    return ans;
  }
};
