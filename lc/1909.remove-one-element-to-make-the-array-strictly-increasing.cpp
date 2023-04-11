/*
 * Problem:
 * https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
 * Tags: Array
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
  bool canBeIncreasing(vector<int> &nums) {
    int previous = nums[0];
    bool used = false;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= previous) { // it's not strictly increasing
        if (used)
          return false;
        // we haven't used the element removal yet.
        used = true;
        if (i == 1 ||
            nums[i] >
                nums[i - 2]) // we remove the element from i - 1 position
                             // because it's bigger, so we update previous.
          previous = nums[i];
        // else we remove current element and leave previous to it's existing
        // value.
      } else
        previous = nums[i];
    }
    return true;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
