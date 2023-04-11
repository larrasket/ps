/*
 * Problem: https://leetcode.com/problems/design-browser-history/
 * Tags: Design
 */

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

class BrowserHistory {
  list<string> history;
  pair<list<string>::iterator, int> curr;

public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    curr.first = history.begin();
  }
  void visit(string url) {
    history.push_back(url);
    curr.first++, curr.second++;
  }

  string back(int steps) {
    steps = (steps > curr.second) ? curr.second : steps;
    curr.second -= steps;
    advance(curr.first, -steps);
    return *(curr.first);
  }

  string forward(int steps) {
    steps = (steps > history.size() - curr.second - 1)
                ? history.size() - curr.second - 1
                : steps;
    if (steps <= 0)
      return *(curr.first);
    curr.second += steps;
    advance(curr.first, steps);
    return *(curr.first);
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
