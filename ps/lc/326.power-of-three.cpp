/*
 * Problem: https://leetcode.com/problems/power-of-three/
 * Tags: Math
 */

#include <algorithm>
#include <array>
#include <bits/types/cookie_io_functions_t.h>
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
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    int d = int(log2(n) / log2(3));
    return pow(3, d) == n;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i = 10;
  auto k = 14.9;
  i = (int)k;
  std::cout << i << std::endl;
}
