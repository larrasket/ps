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
  int n;
  vector<vector<int>> ans;
  void back(int s, vector<int> &dump, vector<int> &nums) {
    ans.push_back(dump);
    if (dump.size() == n) {
      return;
    }
    for (int i = s; i < n; i++) {
      dump.push_back(nums[i]);
      back(i + 1, dump, nums);
      dump.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> d;
    n = nums.size();
    back(0, d, nums);
    return ans;
  }
};
