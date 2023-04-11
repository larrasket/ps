/*
 * Problem: https://leetcode.com/problems/product-of-array-except-self/
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

class Solution {
public:
  vector<long long> productExceptSelf(vector<int> &nums) {
    // get prodcut
    int p = 1, zs = 0, zi = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (!nums[i]) {
        zs++;
        zi = i;
        continue;
      }
      p *= nums[i];
    }
    if (!zs) {
      for (auto &i : nums) {
        i = p / i;
      }
    } else if (zs == 1) {
      fill(begend(nums), 0);
      nums[zi] = p;
    } else {
      fill(begend(nums), 0);
    }
    return vector<long long>(begend(nums));
  }
};
