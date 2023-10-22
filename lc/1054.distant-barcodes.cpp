#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
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
class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &nums) {
    if (nums.size() == 1 || nums.size() == 0)
      return nums;
    unordered_map<int, int> freq;
    for (auto &it : nums)
      freq[it]++;
    priority_queue<pair<int, int>> q;
    for (auto &it : freq)
      q.push(make_pair(it.second, it.first));
    nums.clear();
    while (q.top().first > 0) {
      pair<int, int> p = q.top();
      q.pop();
      nums.push_back(p.second);
      p.first--;
      pair<int, int> p2 = q.top();
      q.pop();
      if (p2.first > 0) {
        nums.push_back(p2.second);
        p2.first--;
      }
      q.push(p);
      q.push(p2);
    }
    return nums;
  }
};
