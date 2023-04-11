/*
 * Problem: https://leetcode.com/problems/integer-replacement/
 * Tags: Dynamic Programming
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
  int minI(long long int n, int ans = 0) {
    if (n == 1)
      return ans;
    if (n % 2 == 0)
      return minI(n / 2, ans + 1);
    else
      return min(minI(n + 1, ans + 1), minI(n - 1, ans + 1));
  }

  int integerReplacement(int n) { return minI(n); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
