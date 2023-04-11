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
  // sort then merge
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {

    vector<vector<int>> ans;
    intervals.push_back(newInterval);
    sort(begend(intervals));

    int n = intervals.size();
    if (n == 1)
      return intervals;
    sort(begend(intervals));
    ans.push_back(intervals[0]);
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] <= intervals[i - 1][1]) {
        ans.pop_back();
        intervals[i][0] = intervals[i - 1][0];
        if (intervals[i][1] < intervals[i - 1][1]) {
          intervals[i][1] = intervals[i - 1][1];
        }
        ans.push_back(intervals[i]);
        continue;
      }
      ans.push_back(intervals[i]);
    }
    return ans;
  }
};
