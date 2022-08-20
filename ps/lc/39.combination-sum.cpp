/*
 * Problem: https://leetcode.com/problems/combination-sum/
 * Tags: Backtracking
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <type_traits>
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
  if (curr == target)
    ans.push_back(kurrent);
  for (int i = index; i < n; i++) {
    vector<int> temp = kurrent;
    temp.push_back(input[i]);
    solve(input, target, ans, n, i, curr + input[i], temp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> test{2, 3, 5};
  vector<vector<int>> myvec;
  int i = 8;
  solve(test, i, myvec, test.size());
  for (auto &k : myvec) {
    for (auto &p : k) {
      cout << p << " ";
      printf("fuck");
    }
    cout << endl;
  }
}
