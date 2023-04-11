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
  int findPeakElement(const vector<int> &num) {
    return Helper(num, 0, num.size() - 1);
  }
  int Helper(const vector<int> &num, int low, int high) {
    if (low == high)
      return low;
    else {
      int mid1 = (low + high) / 2;
      int mid2 = mid1 + 1;
      if (num[mid1] > num[mid2])
        return Helper(num, low, mid1);
      else
        return Helper(num, mid2, high);
    }
  }
};
