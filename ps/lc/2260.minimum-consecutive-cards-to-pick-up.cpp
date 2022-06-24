/*
 * Problem: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
 * Tags: Sliding Window
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
int minimumCardPickup(vector<int> &cards) {
  map<int, int> mp;
  int min = INT_MAX, n = cards.size();
  for (int l = 0, r = 0; r < cards.size(); r++) {
    if (mp.count(cards[r])) {
      int rs = r - mp[cards[r]] + 1;
      min = min > rs ? rs : min;
    }
    mp[cards[r]] = r;
  }
  return min == INT_MAX ? -1 : min;
}
int main() {
  vector<int> r = {1, 0, 5, 3};
  cout << minimumCardPickup(r);
}
