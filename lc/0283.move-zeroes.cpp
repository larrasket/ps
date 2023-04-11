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
  void moveZeroes(vector<int> &nums) {
    int i(0), n(nums.size());
    while (i < n) {
      if (nums[i] != 0) {
        int t = i;
        int j = t - 1;
        while (j >= 0 && nums[j] == 0) {
          swap(nums[t], nums[j]);
          t--;
          j--;
        }
      }
      i++;
    }
  }
};
