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
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    map<int, int> mp;
    int n = difficulty.size(), ans = 0;
    if (n == 1)
      return profit[0];

    for (int i = 0; i < n; i++)
      mp[difficulty[i]] = max(profit[i], mp[difficulty[i]]);
    int end = (--mp.end())->first, mx = 0;
    for (int i = mp.begin()->first; i <= end; i++)
      mx = max(mx, mp[i]), mp[i] = mx;
    for (auto &i : worker)
      if (i > end)
        ans += mx;
      else
        ans += mp[i];
    return ans;
  }
};
