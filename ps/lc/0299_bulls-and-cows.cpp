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
  string getHint(string secret, string guess) {
    map<char, int> mp;
    int c(0), b(0), n(guess.size());
    for (auto &i : secret) {
      mp[i]++;
    }
    for (int i = 0; i < n; i++) {
      if (mp[guess[i]] && guess[i] == secret[i]) {
        mp[guess[i]]--;
        b++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (mp[guess[i]] && guess[i] != secret[i]) {
        mp[guess[i]]--;
        c++;
      }
    }
    return to_string(b) + "A" + to_string(c) + "B";
  }
};
