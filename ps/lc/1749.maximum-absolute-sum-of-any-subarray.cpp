/*
 * Problem: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
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
#include <functional>
#define sz(v) ((int)((v).size()))
using namespace std;

int maxSubArray(vector<int> &nums) { // from the old problem
  int n = nums.size();
  int maxSum = nums[0];
  int currSum = 0;
  for (int i = 0; i < n; i++) {
    currSum += nums[i];
    if (currSum > maxSum) {
      maxSum = currSum;
    }
    if (currSum < 0) {
      currSum = 0;
    }
  }
  return maxSum;
}
int maxAbsoluteSum(vector<int> &nums) {
  int MaxOrigin = maxSubArray(nums);
  std::transform(nums.begin(), nums.end(), nums.begin(),
                 std::bind(std::multiplies<int>(), std::placeholders::_1, -1));
  int MaxMinus = maxSubArray(nums);
  return (MaxOrigin > MaxMinus) ? MaxOrigin : MaxMinus;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
