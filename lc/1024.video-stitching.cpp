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
  int videoStitching(vector<vector<int>> &clips, int time) {
    int res = 0, start = INT_MAX, end = INT_MIN;
    sort(begend(clips));
    auto last = clips[0];
    start = min(start, last[0]);
    end = max(end, last[1]);
    res++;
    for (int i = 1; i < clips.size(); i++) {
      auto flag = false;
      if (clips[i][0] > last[1] || clips[i][1] > last[1]) {
        cout << "END: " << end << " " << clips[i][1] << endl;
        start = min(start, clips[i][0]);
        end = max(end, clips[i][1]);
        flag = 1;
        if (clips[i][0] != last[0])
          res++;
      }
      if (flag) {
        last = clips[i];
      }
    }
    if (start != 0 || end != time)
      return -1;
    return res;
  }
};
