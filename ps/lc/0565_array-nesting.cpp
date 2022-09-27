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
  int arrayNesting(vector<int> &nums) {
    if (!nums.size())
      return 0;
    map<int, bool> mp;
    int ans(1), last(nums[0]);
    mp[last] = 1;
    while (1) {
      if (mp[nums[last]])
        break;
      mp[nums[last]] = 1;
      last = nums[last];
      ans++;
    }
    return ans;
  }
};
