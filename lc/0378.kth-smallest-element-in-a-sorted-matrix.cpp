
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
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &i : matrix) {
      for (auto &b : i) {
        pq.push(b);
      }
    }
    for (int i = 0; i < k - 1; i++) {
      pq.pop();
    }
    return pq.top();
  }
};
