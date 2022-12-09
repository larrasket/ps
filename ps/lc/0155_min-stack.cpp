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

class MinStack {
  stack<int> s;
  stack<int> m;
  stack<int> d;
  int dump;

public:
  MinStack() { dump = 0; }

  void push(int val) {
    if (s.empty()) {
      s.push(val);
      m.push(val);
      return;
    }
    if (val < m.top()) {
      s.push(val);
      d.push(dump);
      m.push(val);
      dump = 0;
      return;
    }
    dump++;
    s.push(val);
  }

  void pop() {
    s.pop();
    if (!dump && !d.empty()) {
      dump = d.top();
      d.pop();
      if (!m.empty())
        m.pop();
      return;
    }
    dump--;
  }

  int top() { return s.top(); }

  int getMin() { return m.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
