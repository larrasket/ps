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
  int evalRPN(vector<string> &tokens) {
    vector<long long> s;
    string g = "+", t = "-", q = "/", d = "*";
    for (auto &i : tokens) {
      if (i == g || i == t || i == q || i == d) {
        long long l, r;
        l = s.back();
        s.pop_back();

        r = s.back();
        s.pop_back();
        if (i == g) {
          s.push_back(r + l);
        } else if (i == t) {
          s.push_back(r - l);
        } else if (i == q) {
          s.push_back(r / l);

        } else if (i == d) {
          s.push_back(r * l);
        }
      } else
        s.push_back(stoi(i));
    }
    return s.back();
  }
};
