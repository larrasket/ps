
/*
 * Problem:
 * https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
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
  int minDeletion(vector<int> &nums) {
    int shift = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if ((i + shift) % 2 == 0) {
        if (nums[i] == nums[i + 1]) {
          shift++;
        }
      }
    }
    if ((nums.size() - shift) % 2 == 1) {
      shift++;
    }
    return shift;
  }
};
int main() {
  vector<int> l{1, 1, 1};
  cout << (l[2] == l[3]);
}
