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
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    map<int, int> mp;
    int n = nums.size();
    for (int i = k - 1; i >= 0; i--) {
      mp[nums[i]]++;
    }
    ans.push_back(mp.rbegin()->first);
    for (int i = k; i < n; i++) {
      mp[nums[i - k]]--;
      if (mp[nums[i - k]] <= 0) {
        auto it = mp.find(nums[i - k]);
        if (it != mp.end())
          mp.erase(it);
      }
      mp[nums[i]]++;
      ans.push_back(mp.rbegin()->first);
    }
    return ans;
  }
};
