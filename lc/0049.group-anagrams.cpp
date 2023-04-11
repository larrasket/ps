/*
 * Problem:
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> m;
    for (auto const &i : strs) {
      auto t = i;
      sort(begend(t));
      m[t].push_back(i);
    }
    vector<vector<string>> ans;
    for (auto const &i : m) {
      ans.push_back(i.second);
    }
    return ans;
    ;
  }
};
