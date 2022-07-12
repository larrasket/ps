/*
 * Problem:
 * Tags:
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
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    int p1 = 0, p2 = k, n = nums.size();
    map<int, int> mp;
    for (; p2 < n; p2 += k) {
      int sum = 0, t = p1;
      while (p1 <= p2) {
        sum += nums[p1], p1++;
      }
      mp[t] = sum;
    }
    auto m = max_element(begend(mp))->first;
    return vector<int>(nums.begin() + m, nums.begin() + m + k);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
