/*
 * Problem: https://www.lintcode.com/problem/920/
 * Tags: Greedy
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
#define begend(v) ((v).begin()), ((v).end())
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

class Solution {
public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: if a person could attend all meetings
   */
  bool canAttendMeetings(vector<Interval> &intervals) {
    sort(begend(intervals),
         [](auto &item1, auto &item2) { return item1.start < item2.start; });
    int n = intervals.size();
    for (int i = 0; i < n - 1; i++) {
      if (intervals[i].end > intervals[i + 1].start)
        return false;
    }
    return true;
  }
};
int main() {
  vector<Interval> l{Interval(1, 2), Interval(9, 10), Interval(0, 6)};
  sort(begend(l));
  for (auto i : l) {
    cout << i.start << endl;
    cout << i.end << endl;
    cout << endl;
  }
}
