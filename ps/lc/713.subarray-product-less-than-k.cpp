/*
 * Problem: https://leetcode.com/problems/subarray-product-less-than-k/solution/
 * Tags: Sliding Window
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

int numSubarrayProductLessThanK(vector<int> &nums, int k) {

  int result = 0, n = nums.size(), sum = 0;
  for (int l = 0, r = 0; r < n; r++) {
    sum *= nums[r];
    while (l <= r && !(sum < k)) {
      sum /= nums[l++];
    }
    if (sum < k)
      result += r - l + 1;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
