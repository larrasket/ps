/*
 * Problem: https://leetcode.com/problems/maximum-sum-circular-subarray/
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

int maxSubarraySumCircular(vector<int> &nums) {
  int n = nums.size();
  int maxSum = INT_MIN;
  int currSum = 0;
  for (int i = 0; i <= n - 1; i++) {
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
