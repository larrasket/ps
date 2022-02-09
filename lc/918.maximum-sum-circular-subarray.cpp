/*
 * Problem: https://leetcode.com/problems/maximum-sum-circular-subarray/
 * Tags: Array
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
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

int maxSubArray(vector<int> &nums, int &totalsum) { // from the old problem
  int n = nums.size();
  int maxSum = nums[0];
  int currSum = 0;
  for (int i = 0; i < n; i++) {
    currSum += nums[i];
    totalsum += nums[i];
    if (currSum > maxSum) {
      maxSum = currSum;
    }
    if (currSum < 0) {
      currSum = 0;
    }
  }
  return maxSum;
}
int maxSubarraySumCircular(vector<int> &nums) {
  int totalsum = 0;
  int MaxOfContinous = maxSubArray(nums, totalsum);
  std::transform(nums.begin(), nums.end(), nums.begin(),
                 std::bind(std::multiplies<int>(), std::placeholders::_1, -1));
  int dummy;
  int Minum = maxSubArray(nums, dummy);
  int MaxOfCurict = totalsum + Minum;

  if (!MaxOfCurict)
    return MaxOfContinous;
  return (MaxOfContinous > MaxOfCurict) ? MaxOfContinous : MaxOfCurict;
}
int main() {
  vector<int> nums{-3, -2, -3};
  cout << maxSubarraySumCircular(nums);
}
