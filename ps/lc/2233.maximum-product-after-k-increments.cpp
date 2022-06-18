/*
 * Problem: https://leetcode.com/problems/maximum-product-after-k-increments/
 * Tags: array
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
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int maximumProduct(vector<int> &nums, int k) {
  int mod = pow(10, 9) + 7;

  while (k) {
    int m = min_element(begend(nums)) - nums.begin();
    nums[m]++;
    k--;
  }
  long long r = 1;
  for (auto &rk : nums) {
    r = (r * rk) % mod;
  }
  return r;
}
int main() {
  vector<int> t = {6, 3, 3, 2};
  cout << maximumProduct(t, 2);
}
