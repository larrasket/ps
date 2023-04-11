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
  int minimumRounds(vector<int> &tasks) {
    int ans(0);
    unordered_map<int, int> c;
    for (auto &ii : tasks) {
      c[ii]++;
    }

    for (auto cc : c) {
      if (cc.second == 1)
        return -1;
      else if (cc.second % 3 == 0) {
        ans += cc.second / 3;
      } else {
        ans += cc.second / 3 + 1;
      }
    }
    return ans;
  }
};
