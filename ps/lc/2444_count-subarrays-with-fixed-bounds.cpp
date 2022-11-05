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
  void handler(int &ans, int &l, int &r, int &n, bool &max, bool min) {}

public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int l(0), r(0), n(nums.size()), s(0);
    long long ans(0);
    bool maxi, mini;
    for (int i = 0; i < n; i++) {
      if (nums[i] > maxK || nums[i] < minK) {
        s = i + 1;
        maxi = 0, mini = 0;
        continue;
      }
      if (nums[i] == maxK) {
        maxi = 1;
        r = i;
      }

      if (nums[i] == minK) {
        mini = 1;
        l = i;
      }
      if (mini && maxi) {
        ans += (min(l, r) - s + 1);
      }
    }

    return ans;
  }
};
