/*
 * Problem: https://leetcode.com/problems/maximum-gap/
 * Tags: Sorting
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
  int maximumGap(vector<int> &nums) {
    int s = sz(nums);
    sort(begend(nums));
    if (s < 2)
      return 0;
    int max = 0, t;
    for (int i = 0; i < s - 1; i++) {
      t = abs(nums[i] - nums[i + 1]);
      if (t > max)
        max = t;
    }
    return max;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
