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
  int sum;
  int m;
  vector<vector<int>> ans;
  void back(vector<int> &d, int s, int c) {
    if (d.size() > m)
      return;
    if (c == sum && d.size() == m) {
      ans.push_back(d);
      return;
    }
    for (int i = s; i <= 9; i++) {
      d.push_back(i);
      back(d, i + 1, c + i);
      d.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    sum = n, m = k;
    vector<int> d;
    back(d, 1, 0);
    return ans;
  }
};
