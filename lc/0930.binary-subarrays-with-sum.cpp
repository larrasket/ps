/*
 * Problem: https://leetcode.com/problems/binary-subarrays-with-sum/
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

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// ______
// [1,0,1,0,1]
// ________
// [1,0,1,0,1]
//    _______
// [1,0,1,0,1]
//      _____

int numSubarraysWithSum(vector<int> &nums, int goal) {

  int n = nums.size(), rs = 0, s = 0;
  auto hlp = [&nums, &n](int goal) {
    int rs = 0, s = 0;
    for (int l = 0, r = 0; r < n; r++) {
      s += nums[r];
      while (s > goal && l <= r) {
        s -= nums[l++];
      }
      rs += r - l + 1;
    }
    return rs;
  };
  return hlp(goal) - hlp(goal - 1);
}

int main() {
  vector<int> r = {1, 0, 1, 0, 1};
  cout << numSubarraysWithSum(r, 2) << endl;
}
