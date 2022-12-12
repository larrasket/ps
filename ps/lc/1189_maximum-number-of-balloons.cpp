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
  int maxNumberOfBalloons(string text) {
    map<char, int> mp;
    string b = "balloon";
    int ans(0);
    for (auto &i : text) {
      mp[i]++;
    }
    while (1) {
      for (auto &i : b) {
        if (mp[i] <= 0) {
          return ans;
        }
        mp[i]--;
      }
      ans++;
    }
    return ans;
  }
};
