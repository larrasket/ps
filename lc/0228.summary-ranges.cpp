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
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ans;
    string next = "->";
    int end, n(nums.size());
    for (int i = 0; i < n;) {
      int start = nums[i], expected = nums[i] + 1;
      i++;
      while (1) {
        if (i >= n) {
          if (start != nums[i - 1])
            ans.push_back(to_string(start) + next + to_string(nums[i - 1]));
          else
            ans.push_back(to_string(start));
          break;
        }
        if (nums[i] != expected) {
          if (start != nums[i - 1])
            ans.push_back(to_string(start) + next + to_string(nums[i - 1]));
          else
            ans.push_back(to_string(start));
          break;
        }
        i++, expected++;
      }
    }
    return ans;
  }
};
