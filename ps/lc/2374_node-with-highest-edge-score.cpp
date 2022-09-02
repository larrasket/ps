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
  int edgeScore(vector<int> &edges) {
    map<long long, long long> mp;
    int ans = 0, inedx = 0;
    for (int i = 0; i < edges.size(); i++) {
      mp[edges[i]] += i;
    }
    for (auto &i : mp) {
      if (i.second > ans) {
        ans = i.second;
        inedx = i.first;
      }
    }
    return inedx;
  }
};
