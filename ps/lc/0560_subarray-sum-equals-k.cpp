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
  int subarraySum(vector<int> &nums, int k) {
    if (nums.size() == 1) {
      return nums[0] == k;
    }
    int ans(0), sum(0);
    map<int, int> mp;
    mp[0] = 1;
    for (auto &i : nums) {
      sum += i;
      if (mp[sum - k])
        ans += mp[sum - k];
      mp[sum]++;
    }
    return ans;
  }
};
