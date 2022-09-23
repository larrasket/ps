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
  string s;
  string t;
  int y(0), wp(0);
  cin >> s >> t;
  map<char, int> mp;
  for (auto &i : t) {
    mp[i]++;
  }
  for (auto &i : s) {
    if (mp[i]) {
      mp[i]--;
      y++;
      continue;
    }
    wp++;
  }
  cout << y << " " << wp;
}
int main() {
  // int t;
  // cin >> t;
  // while (t)
  solve();
}

/*
**

caba
yay
yay
yay

ACBA

**
*/
