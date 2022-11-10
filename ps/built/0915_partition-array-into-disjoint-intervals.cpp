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
  int partitionDisjoint(vector<int> &nums) {
    int n = nums.size(), ans(0), maxleft(0), maxright(0), rp(0);
    for (int i = 0; i < n; i++) {
      if (nums[i] > maxleft)
        maxleft = nums[i];
    }

    return ans;
  }
};
