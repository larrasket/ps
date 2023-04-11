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
  unordered_map<int, int> mp;

public:
  int coinChange(vector<int> &coins, int amount) {
    if (!amount)
      return 0;
    if (amount < 0)
      return -1;
    if (mp.count(amount)) {
      return mp[amount];
    }
    int ans = -1;
    for (auto &i : coins) {
      int pans = coinChange(coins, amount - i);
      if (pans == -1)
        continue;
      int cand = pans + 1;
      if (ans == -1 || cand < ans)
        ans = cand;
    }
    mp[amount] = ans;
    return ans;
  }
};
