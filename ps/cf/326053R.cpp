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
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mp[t]++;
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mp[t]--;
  }
  for (auto &i : mp)
    if (i.second) {
      cout << "no";
      return;
    }

  cout << "yes";
}
int main() {
  // int t;
  // cin >> t;
  // while (t)
  solve();
}
