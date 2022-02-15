/*
 * Problem: https://codeforces.com/contest/1632/problem/A
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

void solve() {
  int k;
  cin >> k;
  string p;
  cin >> p;
  if (p.length() < 2)
    cout << "YES" << endl;
  else if (p.length() == 2) {
    auto te = p;
    reverse(begend(te));
    if (te == p)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n) {
    solve();
    n--;
  }
}
