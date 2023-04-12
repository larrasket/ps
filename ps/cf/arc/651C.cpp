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
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  vector<pair<int, int>> pars;
  auto doc = [&](pair<int, int> &pos1, pair<int, int> &pos2) {
    return sqrt(pow(pos1.first - pos2.first, 2) +
                pow(pos1.second - pos2.second, 2));
  };

  auto frind = [&](pair<int, int> &pos1, pair<int, int> &pos2) {
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
  };

  auto checkall = [&](pair<int, int> &pos) -> int {
    int s = 0;
    for (auto &i : pars) {
      if (abs(doc(i, pos)) == abs(frind(i, pos)))
        s++;
    }
    return s;
  };
  for (int i = 0; i < n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    pair<int, int> p{t1, t2};
    ans += checkall(p);
    pars.push_back(p);
  }
  cout << ans;
}
int main() {
  // int t;
  // cin >> t;
  // while (t)
  solve();
}
