/*
 * Problem: https://leetcode.com/problems/3sum/
 * Tags: Array
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

vector<vector<int>> threeSum(vector<int> &nums) {
  sort(begend(nums));
  int sum;
  vector<vector<int>> ans;
  map<int, bool> mymap;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (!mymap[nums[i]]) {
      mymap[nums[i]] = true;
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          sum = nums[i] + nums[j] + nums[k];
          if (sum == 0) {
            ans.push_back((vector<int>){nums[i], nums[j], nums[k]});
          }
          if (sum > 0)
            break;
        }
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> input{
      -1,  -12, 14,  -6,  4,   -11, 2,   -7,  13,  -15, -1,  11, -15, -15, 13,
      -9,  -11, -10, -7,  -13, 7,   9,   -13, -3,  10,  1,   -5, 12,  11,  -9,
      2,   -4,  -6,  -7,  5,   5,   -2,  14,  13,  -12, 14,  -3, 14,  14,  -11,
      5,   12,  -6,  10,  -9,  -4,  -6,  -15, -9,  -1,  2,   -1, 9,   -9,  -5,
      -15, 8,   -2,  -6,  9,   10,  7,   14,  9,   5,   -13, 9,  -12, 8,   8,
      -8,  -2,  -2,  1,   -15, -4,  5,   -13, -4,  3,   1,   5,  -13, -13, 11,
      -11, 10,  5,   3,   11,  -9,  -2,  3,   -10, -7,  -6,  14, 9,   -11, 7,
      2,   -4,  13,  7,   5,   13,  -12, -13, 7,   -9,  5,   -7, 11,  -1,  -12,
      8,   3,   13,  -10, 13,  1,   -4};
  auto k = threeSum(input);
  for (auto &i : k) {
    for (auto &j : i) {
      cout << j << endl;
    }
    cout << endl;
  }
}
