/*
 * Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
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

class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
    while (r < n) {
      sum += nums[r++];
      while (sum >= s) {
        len = min(len, r - l);
        sum -= nums[l++];
      }
    }
    return len == INT_MAX ? 0 : len;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
