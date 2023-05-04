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
  int findMiddleIndex(vector<int> &nums) {
    int sum1(0), sum2(0), n(nums.size());
    for (auto &i : nums) {
      sum1 += i;
    }
    for (int i = 0; i < n; i++) {
      sum1 -= nums[i];
      if (sum1 == sum2) {
        return i;
      }
      sum2 += nums[i];
    }
    return -1;
  }
};
