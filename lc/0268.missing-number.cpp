/*
 * Problem: https://leetcode.com/problems/missing-number/
 * Tags: Math
 */

// #include <algorithm>
// #include <array>
// #include <climits>
// #include <cmath>
// #include <deque>
// #include <iomanip>
// #include <iostream>
// #include <iterator>
// #include <list>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <set>
// #include <stack>
// #include <string>
// #include <tuple>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// #define begend(v) ((v).begin()), ((v).end())
// #define sz(v) ((int)((v).size()))
// using namespace std;

// int missingNumber(vector<int> &nums) {
//   int sum = 0, m = 0, asum;
//   bool havezero = 0;
//   for (auto &i : nums) {
//     sum += i;
//     if (i > m)
//       m = i;
//     if (!i)
//       havezero = 1;
//   }
//   int ans = (m * (m + 1)) / 2 - sum;
//   if (!ans && havezero) {
//     return m + 1;
//   }
//   return ans;
// }
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
// }

#include <algorithm>

int main() {
  int i = 1;
  int k = 2;
}
