/*
 * Problem: https://codeforces.com/contest/1634/problem/A
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
  int n;
  int k;
  cin >> n;
  cin >> k;
  string p;
  cin >> p;
  auto revers = p;
  reverse(begend(revers));
  if (p == revers || k == 0) {
    cout << 1 << endl;
  } else {
    cout << 2 << endl;
  }
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
