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
  int numRabbits(vector<int> &answers) {
    int ans(0);
    unordered_map<int, int> va;
    for (auto &i : answers) {
      if (!i) {
        ans++;
        continue;
      }
      if (!va[i]) {
        ans += i + 1;
        continue;
      }
      va[i]++;
      if (va[i] == i) {
        va[i] = 0;
      }
    }
    return ans;
  }
};