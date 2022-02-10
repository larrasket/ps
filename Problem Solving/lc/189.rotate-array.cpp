
/*
 * Problem: https://leetcode.com/problems/rotate-array/
 * Tags: Two Pointers
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

void _rotate(vector<int> &nums, int k) {
  vector<int> temp;
  k = k > nums.size() ? k % nums.size() : k;
  temp.assign(nums.end() - k, nums.end());
  temp.insert(temp.end(), nums.begin(), nums.end() - k);
  nums = temp;
  for (auto &i : nums) {
    cout << i << " ";
  }
}

int main() {
  vector<int> t{1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  _rotate(t, 3);
}
