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
  string composed(int n) {
    string res;
    for (int i = 0; i < n; i++) {
      res += '(';
    }
    for (int i = 0; i < n; i++) {
      res += ')';
    }
    return res;
  }
  string out(int n) {
    string res;
    for (int i = 0; i < n; i++) {
      res += "()";
    }
    return res;
  }
  void backtrack(int n, vector<string> &res, string current = "") {
    if (current.size() == n * 2) {
      res.push_back(current);
      return;
    }
    for (int i = 0; i < n; i++) {
      backtrack(n, res, current + composed(i));
      backtrack(n, res, current + out(i));
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(n, res);
    return res;
  }
};
