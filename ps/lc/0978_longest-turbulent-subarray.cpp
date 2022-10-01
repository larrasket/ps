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

// 9,4,2,10,7,8,8,1,9
// 0 1 2 3 4 5 6 7 8

class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();
    int ans(0), l(0), r(1);
    while (r < n - 1) {
      while (r < n - 1 && (arr[r - 1] > arr[r] < arr[r + 1] ||
                           arr[r - 1]<arr[r]> arr[r + 1]))
        r++;
      while (l < r && arr[l] == arr[l + 1])
        l++;
      ans = (r - l + 1) > ans ? (r - l + 1) : ans;
      l = r;
      r++;
    }
    return ans;
  }
};
