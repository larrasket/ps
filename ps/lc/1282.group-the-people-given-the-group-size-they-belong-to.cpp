/*
 * Problem:
 * https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
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

vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
  map<int, vector<int>> m;
  int n = groupSizes.size();
  for (int i = 0; i < n; i++) {
    m[groupSizes[i]].push_back(i);
  }
  vector<vector<int>> l;
  for (auto iter = m.begin(); iter != m.end(); ++iter) {
    int n = iter->second.size() / iter->first;
    auto s = iter->second.begin();
    auto e = iter->second.begin();
    advance(e, iter->first);
    while (n) {
      l.push_back(vector<int>(s, e));
      advance(s, iter->first);
      advance(e, iter->first);
      n--;
    }
  }
  return l;
}

int main() { vector<int> l{1, 2, 3, 4}; }
