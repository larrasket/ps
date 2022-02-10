/*
 * Problem:
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Tags: Binary Search
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

vector<int> searchRange(vector<int> &nums, int target) {

  int n = nums.size();
  int r = n - 1, l = 0;
  int m = l + (r - l) / 2;
  int p = -1;
  while (r >= l) {
    m = l + (r - l) / 2;
    if (target == nums[m])
      p = m;
    if (target > nums[m])
      l = m + 1;
    else
      r = m - 1;
  }
  if (p == -1)
    return (vector<int>){-1, -1};
  vector<int> ans;
  int temp = p;
  while (temp - 1 >= 0 && nums[p] == nums[temp - 1]) {
    temp--;
  }
  ans.push_back(temp);
  temp = p;
  while (temp + 1 < n && nums[p] == nums[temp + 1]) {
    temp++;
  }
  ans.push_back(temp);
  return ans;
}
int main() {

  vector<int> test = {5, 7, 7, 8, 8, 10};
  auto k = searchRange(test, 8);
  for (auto &i : k) {
    cout << i << endl;
  }
}
