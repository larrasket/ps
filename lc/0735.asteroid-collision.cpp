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
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> stack;
    vector<int> ans;
    stack.push(asteroids[0]);
    int i = 1;
    while (i < asteroids.size()) {
      bool apos = asteroids[i] > 0, spos = stack.top() > 0;
      if (apos == spos) {
        stack.push(asteroids[i]);
        i++;
        continue;
      }
      while (apos != spos) {
        if (abs(asteroids[i]) > abs(stack.top())) {
          stack.pop();
        } else if (abs(asteroids[i]) == abs(stack.top())) {
          stack.pop();
          i++;
        } else if (abs(asteroids[i]) < abs(stack.top())) {
          i++;
        }
        if ((i >= asteroids.size()))
          break;
        apos = asteroids[i] > 0, spos = stack.top() > 0;
      }
      if ((i >= asteroids.size()))
        break;
      stack.push(asteroids[i]);
      i++;
    }

    while (!stack.empty())
      ans.push_back(stack.top()), stack.pop();
    return vector<int>(ans.rbegin(), ans.rend());
  }
};
