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

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//                     1--3
//                      2----6
//                               8---10
//                                        15----18
// Output:            [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if (n == 1)
      return intervals;
    vector<vector<int>> ans;
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
