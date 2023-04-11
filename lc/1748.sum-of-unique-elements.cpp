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
  int sumOfUnique(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (auto &i : nums) {
      mp[i]++;
    }
    int ans(0);
    for (auto &i : mp) {
      if (i.second == 1)
        ans += i.first;
    }
    return ans;
  }
};
