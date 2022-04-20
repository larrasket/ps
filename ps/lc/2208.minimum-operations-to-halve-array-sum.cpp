/*
 * Problem: 2208. Minimum Operations to Halve Array Sum
 * Tags: Greedy
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
  int halveArray(vector<int> &nums) {
    int ans = 0, sum = 0, n = nums.size();
    double nsum;
    for (auto const &i : nums) {
      sum += i;
    }
    nsum = sum;
    int i = 0;
    while (sum > (nsum / 2)) {
      if (i == n)
        i = 0;
      if (i < n - 1 && nums[i + 1] > nums[i])
        i++;
      double del = (double)nums[i] / 2;
      nums[i] = del, ans++, i++, nsum -= del;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
