/*
 * Problem: https://leetcode.com/problems/decode-ways/
 * Tags: Dynamic Programming
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdlib>
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

map<int, bool> checked;

void solve(string &o, int &len, int &methods, int index = 0, string curr = "") {
  int n = stoi(curr);
  if (checked[n])
    return;
  if (n > 26 || n < 1)
    return;
  if (index >= len) {
    methods++;
    return;
  }
  checked[n] = true;
  string s(1, o[index]);
  solve(o, len, methods, index + 1, s);
  solve(o, len, methods, index + 1, (curr + o[index]));
}
int main() {
  string s = "111111111111111111111111111111111111111111111";
  int r = 0;
  int n = s.length();
  solve(s, n, r, 1, string(1, s[0]));
  cout << r << endl;
}
