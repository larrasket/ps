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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
map<char, vector<int>> mp{
    {'2', {2}},    {'3', {3}}, {'4', {3, 2, 2}},    {'5', {5}},
    {'6', {5, 3}}, {'7', {7}}, {'8', {7, 2, 2, 2}}, {'9', {7, 3, 3, 2}}};
void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] != '0' && a[i] != '1')
      ans.insert(ans.end(), begend(mp[a[i]]));
  }
  sort(begend(ans), greater<char>());
  for (auto &i : ans) {
    cout << i;
  }
  cout << endl;
}

int main() {
  // int t;
  // cin >> t;
  // while (t)
  solve();
}
