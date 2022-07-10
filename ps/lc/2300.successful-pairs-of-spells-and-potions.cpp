/*
 * Problem:
 * https://leetcode.com/problems/successful-pairs-of-spells-and-potions/ Tags:
 * Two Pointers
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
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    vector<int> r;
    int n(potions.size());
    sort(begend(potions));

    for (auto &i : spells) {
      int s(0), en(n);
      while (s < en) {
        int m = s + (en - s) / 2;
        ((long long)i * potions[m] >= success) ? en = m : s = m + 1;
      }
      r.push_back(n - s);
    }
    return r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
