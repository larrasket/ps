/*
 * Problem: https://leetcode.com/problems/subsets-ii/
 * Tags: Dynamic Programming
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
void solve(vector<int> &Numbers, vector<vector<int>> &ans, int p,
           vector<int> tempvec = {}) {
  if (p == Numbers.size() || Numbers[p] == Numbers[p - 1])
    return;
  ans.push_back(tempvec);
  int i = p + 1;
  for (; i < Numbers.size(); i++) {
    tempvec.push_back(Numbers[i]);
    solve(Numbers, ans, i, tempvec);
    tempvec.pop_back();
  }
  return;
}
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  vector<vector<int>> ans;
  solve(nums, ans, -1);
  return ans;
}
int main() {
  vector<int> k{1, 2, 2};
  vector<vector<int>> ans = subsetsWithDup(k);
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j << endl;
    }
    cout << endl;
    ;
  }
}
