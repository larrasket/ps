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
  int characterReplacement(string s, int k) {
    map<char, int> mp;
    int n(s.size()), j(0), sum(0), res(-1);
    for (int i = 0; i < n; i++) {
      mp[s[i]]++, sum++;
      while (j < n && mp.size() > 1) {
        mp[s[j]]--, sum--;
        if (mp[s[j]] == 0) {
          mp.erase(s[j]);
          j++;
        }
      }
      res = max(res, sum);
    }
    return res;
  }
};
