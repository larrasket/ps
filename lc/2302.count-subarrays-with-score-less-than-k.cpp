/*
 * Problem:
 * https://leetcode.com/problems/count-subarrays-with-score-less-than-k/ Tags:
 * Array, Slinding Window
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
long long countSubarrays(vector<int> &nums, long long k) {
  long long result = 0, n = nums.size(), sum = 0;
  for (int l = 0, r = 0; r < n; r++) {
    sum += nums[r];
    auto vk = sum * (r - l + 1);
    while (l <= r && !(vk < k)) {
      sum -= nums[l++];
      vk = sum * (r - l + 1);
    }
    if (vk < k)
      result += r - l + 1;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
