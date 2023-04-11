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
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    unordered_map<int, bool> m;
    for (auto &i : nums) {
      m[i] = 1;
    }
    vector<int> ans;
    for (int i = 1; i <= nums.size(); i++) {
      if (!m[i]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
