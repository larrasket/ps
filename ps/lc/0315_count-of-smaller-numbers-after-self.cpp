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
  vector<int> countSmaller(vector<int> &nums) {
    vector<int> ans(nums.size());
    multiset<int> mp;
    int n(nums.size());
    int j(n - 1);
    for (int i = n - 1; i >= 0; i--, j--) {
      mp.insert(nums[i]);
      int k = distance(mp.begin(), mp.lower_bound(nums[i]));
      ans[j] = k;
    }
    return ans;
  }
};

// int main() {
//   vector<int> x{1, 2, 3, 3, 5};
//   cout << (lower_bound(begend(x), 2) - begin(x));
//   return 0;
// }
