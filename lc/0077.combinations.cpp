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

class Solution {
  int m;
  int e;
  vector<vector<int>> ans;
  void solve(int s, vector<int> &d) {
    if (d.size() == e) {
      ans.push_back(d);
      return;
    }
    for (int i = s; i <= m; i++) {
      d.push_back(i);
      solve(i + 1, d);
      d.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    m = n, e = k;
    vector<int> d;
    solve(1, d);
    return ans;
  }
};
