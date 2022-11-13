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
  int numberOfSubstrings(string s) {
    int ans(0), n(s.size()), t(0);
    unordered_map<char, int> mp;
    for (int i = 0, j = 0; i < n; i++) {
      mp[s[i]]++;
      while (j < n && mp['a'] && mp['b'] && mp['c']) {
        t++;
        mp[s[j]]--;
        j++;
      }
      ans += t;
    }
    return ans;
  }
};
