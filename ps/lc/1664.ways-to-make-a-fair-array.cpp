/*
 * Problem: https://leetcode.com/problems/ways-to-make-a-fair-array/
 * Tags: Dynamic Programming
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
  int waysToMakeFair(vector<int> &nums) {
    int es = 0, os = 0, n = nums.size(), l = 0;
    vector<int> sums(n);
    for (int i = n - 1; i >= 0; i--) {
      if (i % 2)
        os += nums[i];
      else
        es += nums[i];
      sums[i] = l;
      l += nums[i];
    }
    bool pov;
    int max, min;
    if (es > os) {
      pov = 0;
      max = es;
      min = os;
    } else if (os > es) {
      pov = 1;
      max = os;
      min = es;
    } else {
      return 0;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((bool)(i % n) != pov)
        continue;
      int t1 = max - sums[i] - nums[i];
      int t2 = min + sums[i];
      if (t1 == t2)
        ans++;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
