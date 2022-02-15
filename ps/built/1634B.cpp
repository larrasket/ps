/*
 * Problem: https://codeforces.com/contest/1634/problem/B
 * Tags: string
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

bool rightSol(vector<int> &arr, int index, int d, int &y) {
  if (index >= arr.size())
    return 0;
  if (d == y)
    return 1;
  bool replace = rightSol(arr, index + 1, arr[index] + d, y);
  bool xo = rightSol(arr, index + 1, d ^ arr[index], y);
  if (replace || xo)
    return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  int alice;
  cin >> alice;
  int y;
  cin >> y;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (rightSol(arr, 0, alice, y))
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n) {
    solve();
    n--;
  }
}
