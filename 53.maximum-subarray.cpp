/*
 * Problem: https://leetcode.com/problems/maximum-subarray/
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

int maxSubArray(vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];
  int lastmainsum = 0, lastsubsum = 0, max = INT_MIN, all;

  for (int i = 0; i < n; i++) {
    lastmainsum += nums[i];
  }
  all = lastmainsum;
  for (int i = 0; i < n; i++) {
    lastmainsum -= (i == 0) ? 0 : nums[i - 1];
    lastsubsum = lastmainsum;
    for (int j = n - 1; j >= i; j--) {
      lastsubsum -= ((j == n - 1) ? 0 : nums[j + 1]);
      cout << lastsubsum << endl;
      if (lastsubsum > max)
        max = lastsubsum;
    }
  }
  return (max > all) ? max : all;
}

int main() {
  vector<int> arr{-2, -1, -4};
  maxSubArray(arr);
}
