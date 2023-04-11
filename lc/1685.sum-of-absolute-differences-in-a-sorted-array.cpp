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
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    vector<int> ans;
    int p(0);
    for (auto &i : nums)
      p += i;
    int n = nums.size();
    int prv = 0;
    int ns(p), ps(0), nns(n), nps(0);
    for (int i = 0; i < n; i++) {
      ns -= nums[i];
      nns--;

      int j = abs(ns - (nums[i] * nns)) + abs(ps - (nums[i] * nps));
      ans.push_back(j);
      ps += nums[i];
      nps++;
    }
    return ans;
  }
};
