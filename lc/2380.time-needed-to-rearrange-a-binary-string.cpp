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
  int sol(string &s, int pos) {
    int ans = 0, n = s.size();
    if (pos >= n)
      return ans;
    for (int i = pos; pos < n; i++) {
      if (s[i] == '1')
        ans++;
      else {
        ans += sol(s, i + 1);
      }
    }
    return ans;
  }
  int secondsToRemoveOccurrences(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        ans += sol(s, i + 1);
        break;
      }
    }
    return ans;
  }
};
