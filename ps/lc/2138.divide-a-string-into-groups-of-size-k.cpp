/*
 * Problem:
 * https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/
 * Tags: String
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
vector<string> divideString(string s, int k, char fill) {
  int n = s.size(), r = n % k, ad = k - r;
  vector<string> ans;
  auto st = s.begin();
  auto en = s.begin();
  en += k;
  while (en <= s.end()) {
    ans.push_back(string(st, en));
    st = en;
    en += k;
  }
  if (r) {
    string t(st, s.end());
    while (ad)
      t.push_back(fill), ad--;
    ans.push_back(t);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
