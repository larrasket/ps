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
  int lengthOfLongestSubstring(string s) {
    // stack<char> st;
    map<char, bool> mp;
    int ans(0);
    int i(0), j(0);
    while (i <= j && j < s.size()) {
      while (mp[s[j]]) {
        mp[s[i]] = 0;
        i++;
      }
      mp[s[j]] = 1;
      ans = max(ans, j - i + 1);
      j++;
    }
    return ans;
  }
};
