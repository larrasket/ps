/*
 * Problem: https://www.lintcode.com/problem/919/?_from=collection&fromId=185
 * Tags: greedy
 */

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
#define sz(v) ((int)((v).size()))
using namespace std;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

#define begend(v) ((v).begin()), ((v).end())
class Solution {
public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: the minimum number of conference rooms required
   */
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(begend(intervals),
         [](auto &item1, auto &item2) { return item1.start < item2.start; });
    int n = intervals.size(), ans = 1;
    for (int i = 0; i < n - 1; i++) {
      if (intervals[i].end > intervals[i + 1].start)
        ans++;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
