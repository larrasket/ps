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
  int minDeletionSize(vector<string> &strs) {
    int n = strs.size(), m = strs[0].size(), ans = 0;
    vector<int> d;
    for (int j = 0; j < m; j++) {
      for (int i = 1; i < n; i++) {
        if (strs[i][j] < strs[i - 1][j]) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};
