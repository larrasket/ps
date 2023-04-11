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
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size(), j(0), ans(-1), c(0);
    bool z = 1;
    for (int i = 0; i < n; i++) {
      if (!nums[i])
        c++;
      else
        z = 0;
      while (c > k && j < n) {
        if (!nums[j])
          c--;
        j++;
      }
      ans = i - j + 1 > ans ? i - j + 1 : ans;
    }
    return ans == -1 ? nums.size() : ans;
  }
};
