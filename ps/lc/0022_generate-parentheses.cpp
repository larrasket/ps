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
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
  }
  void addingpar(vector<string> &v, string str, int n, int m) {
    if (n == 0 && m == 0) {
      v.push_back(str);
      return;
    }
    if (n > 0) {
      addingpar(v, str + "(", n - 1, m + 1);
    }

    if (m > 0) {
      addingpar(v, str + ")", n, m - 1);
    }
  }
};
