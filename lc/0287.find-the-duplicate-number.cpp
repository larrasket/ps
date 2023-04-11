/*
 * Problem: https://leetcode.com/problems/find-the-duplicate-number/
 * Tags: Hashtable
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
int findDuplicate(vector<int> &nums) {
  map<int, bool> e;
  for (auto &i : nums) {
    if (e[i])
      return i;
    e[i] = true;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
