/*
 * Problem: https://leetcode.com/problems/non-decreasing-array/
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

bool checkPossibility(vector<int> &nums) {
  int n = sz(nums);
  if (n == 1)
    return 1;
  int df = 0;
  int mf = 0;
  int mx = INT_MIN;
  for (int i = 1; i < n; i++) {
    if (nums[i] < nums[i - 1]) {
      df++;
      mx = nums[i - 1];
    }
    if (mx > nums[i])
      mf++;
  }
  return df == 1 && mf == 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> i{1, 2, 3, 4};
  cout << i[12233] << endl;
  cout << "WQ";
}
