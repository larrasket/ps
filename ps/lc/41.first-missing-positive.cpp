/*
 * Problem: https://leetcode.com/problems/first-missing-positive/
 * Tags: Negative Markting
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
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (auto &i : nums)
      if (i > n || 0 >= i)
        i = 1, nums[i - 1] *= -1;
      else
        nums[i - 1] *= -1;

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0)
        return i + 1;
    }
    return n + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
