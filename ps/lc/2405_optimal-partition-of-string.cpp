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
  int partitionString(string s) {
    int n = s.size(), ans(0), start(0);
    map<char, int> count;
    for (int i = 0; i < n; i++) {
      count[s[i]]++;
      if (count[s[i]] > 1) {
        ans++;
        count.clear();
        count[s[i]]++;
      }
    }
    return ans + 1;
  }
};
