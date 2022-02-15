/*
 * Problem: https://codeforces.com/contest/1637/problem/0
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

void sol() {
  int n;
  cin >> n;
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  int no = 1;
  for (int i = 1; i < q.size(); i++) {
    auto tempq = q;
    sort(tempq.begin(), tempq.begin() + i);
    sort(tempq.begin() + i, tempq.end());

    if (!is_sorted(begend(tempq))) {
      cout << "YES" << endl;
      no = 0;
      break;
    }
  }
  if (no)
    cout << "NO";
}

int main() {
  int n;
  cin >> n;
  while (n) {
    sol();
    n--;
  }
}
