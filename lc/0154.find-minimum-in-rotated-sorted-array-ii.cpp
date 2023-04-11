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
  int findMin(vector<int> &nums) {
    int n = nums.size(), l = 0, r = n - 1, m;
    if (n == 1)
      return nums[0];
    while (l < r) {
      m = l + (r - l) / 2;
      if (m > 0 && nums[m] < nums[m - 1])
        return nums[m];
      if (nums[m] > nums[r]) // left sorted, right not
      {
        l = m + 1;
        continue;
      } else if (nums[m] < nums[l])
        r = m - 1;
      else
        r--;
    }
    return nums[l];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
