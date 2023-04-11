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
  map<int, bool> used;
  int n;
  void backtrack(vector<int> &nums, vector<int> &current,
                 vector<vector<int>> &result) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        current.push_back(nums[i]);
        used[i] = 1;
        backtrack(nums, current, result);
        used[i] = 0;
        current.pop_back();
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curren;
    n = nums.size();
    backtrack(nums, curren, res);
    return res;
  }
};
