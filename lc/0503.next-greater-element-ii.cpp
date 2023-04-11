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
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size(), m = nums[n - 1];
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n * 2; i++) {
      while (s.size() && nums[i % n] > nums[s.top() % n]) {
        ans[s.top() % n] = nums[i % n];
        s.pop();
      }
      s.push(i % n);
    }
    return ans;
  }
};
