/*
 * Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/
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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

vector<pair<string, int>> subString(string &str) {
  int n = str.length();
  vector<pair<string, int>> s;
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      string temp = str.substr(i, n - (i + len - 1));
      sort(begend(temp));
      s.push_back({temp, i});
    }
  }
  return s;
}

void subString(string str, int n) {
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      cout << str.substr(i, n - j);
      cout << endl;
    }
  }
}

vector<int> findAnagrams(string s, string p) {
  vector<int> ans;
  auto subs = subString(s);
  sort(begend(p));
  for (auto &q : subs) {
    if (q.first == p)
      ans.push_back(q.second);
  }
  return ans;
}

vector<pair<string, int>> ssubString(string &str, int strln) {
  int n = str.length();
  vector<pair<string, int>> subs;
  for (int i = 0; i < n - strln; i++) {
    cout << i << endl;
    string temp = str.substr(i, strln);
    subs.push_back({temp, i});
  }
  int t = n % strln;
  if (t) {
    string k = str.substr(n - strln, strln);
    sort(begend(k));
    subs.push_back({k, n - strln});
  }
  return subs;
}

// "aaaaaaaaaa"
// "aaaaaaaaaaaaa"
int main() {
  string s = "aaaaaaaaaa";
  string p = "aaaaaaaaaaaaa";
  vector<int> ans;
  auto subs = ssubString(s, p.length());
  sort(begend(p));
  for (auto &q : subs) {
    if (q.first == p)
      ans.push_back(q.second);
  }
}
