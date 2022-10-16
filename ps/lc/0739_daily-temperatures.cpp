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
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> sk;
    for (int i = n - 1; i >= 0; i--) {
      while (!sk.empty() && temperatures[sk.top()] <= temperatures[i]) {
        sk.pop();
      }
      if (!sk.empty()) {
        ans[i] = sk.top() - i;
      }
      sk.push(i);
    }
    return ans;
  }
};
