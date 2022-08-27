#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>> pq;

class Solution {

public:
  int maximumSum(vector<int> &nums) {
    int ans = -1;
    for (auto &i : nums) {
      int sum = 0, num = i;
      while (i > 0) {
        sum += i % 10;
        i = i / 10;
      }
      pq.push({num, sum});
    }
    map<int, int> mp;
    int n = pq.size();
    for (int i = 0; i < n; i++) {
      auto now = pq.top();
      if (mp[now.second] != 0) {
        return now.first + mp[now.second];
      }
      mp[now.second] = now.first;
    }
    return -1;
  }
};
