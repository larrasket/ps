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
  int findMaxK(vector<int> &nums) {
    map<int, bool> mp;
    for (auto &i : nums) {
      mp[i] = 1;
    }
    sort(begend(nums), greater<int>());
    for (auto &i : nums) {
      if (mp[i * -1])
        return i;
    }
    return -1;
  }
};
