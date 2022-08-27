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
  int minimumRecolors(string blocks, int k) {
    int ans = 0, n = blocks.size();
    for (int i = 0; i < k && i < n; i++) {
      if (blocks[i] == 'W')
        ans++;
    }
    int kans = ans;
    for (int i = k; i < n; i++) {
      if (blocks[i] == 'W')
        kans++;
      if (blocks[i - k] == 'W')
        kans--;
      ans = kans < ans ? kans : ans;
    }
    return ans > 0 ? ans : 0;
  }
};
