/*
 * Problem: https://leetcode.com/problems/single-number/
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
  int singleNumber(vector<int> &nums) {
    map<int, int> m;
    for (const int &i : nums) {
      m[i]++;
    }
    auto i = min_element(m.begin(), m.end(), [](const auto &i, const auto &j) {
      return j.second > i.second;
    });
    return (i)->first;
  }
};

int main() {
  Solution p;
  vector<int> t{1, 1, 2, 3, 2, 3, 3, 5, 5, 13, 11};
  p.singleNumber(t);
}
