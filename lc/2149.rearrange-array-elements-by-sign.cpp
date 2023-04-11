/*
 * Problem: https://leetcode.com/problems/rearrange-array-elements-by-sign/
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

vector<int> rearrangeArray(vector<int> &nums) {
  vector<int> ans;
  int i = 0, j = 0, n = nums.size();
  int round = 0;
  while (i < n || j < n) {
    if (round % 2) {
      while (j < n && nums[j] > 0)
        j++;
      if (j < n) {
        ans.push_back(nums[j]);
        j++;
      }
    } else {
      while (i < n && nums[i] < 0)
        i++;
      if (i < n) {
        ans.push_back(nums[i]);
        i++;
      }
    }
    round++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> o{28, -41, 22,  -8,  -37, 46, 35, -9, 18,
                -6, 19,  -26, -37, -10, -9, 15, 14, 31};
  auto mm = rearrangeArray(o);
  for (auto l : mm) {
    cout << l << endl;
  }
}
