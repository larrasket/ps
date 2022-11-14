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
  bool increasingTriplet(vector<int> &nums) {
    int small = INT_MAX, max(INT_MAX);
    for (auto &i : nums) {
      if (i <= small) {
        small = i;
      } else if (i <= max)
        max = i;
      else
        return 1;
    }
    return 0;
  }
};
