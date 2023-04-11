/*
 * Problem: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Tags: Math
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

int maximumproduct(vector<int> &nums) {
  sort(begend(nums), greater<>());
  int n = nums.size();
  int x = nums[0] * nums[1] * nums[2];
  return max(x, nums[0] * nums[n - 1] * nums[n - 2]);
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> i{-100, -98, -1, 2, 3, 4};
  cout << maximumproduct(i);
  cin.tie(NULL);
}
