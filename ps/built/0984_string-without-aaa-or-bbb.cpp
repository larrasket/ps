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
  string strWithout3a3b(int a, int b) {
    string ans;
    while (a > 0 || b > 0) {
      bool wa = 0;
      int l = ans.length();
      if (l >= 2 && ans[l - 2] == ans[l - 1]) {
        if (ans[l - 1] == 'a')
          wa = 0;
        else
          wa = 1;
      }
      if (wa) {
        ans += 'a';
        a--;
      } else {
        ans += 'b';
        b--;
      }
    }
    return ans;
  }
};
