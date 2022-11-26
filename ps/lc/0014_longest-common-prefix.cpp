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
  string longestCommonPrefix(vector<string> &str) {
    int n = str.size();
    if (n == 0)
      return "";

    string ans = "";
    sort(begin(str), end(str));
    string a = str[0];
    string b = str[n - 1];

    for (int i = 0; i < a.size(); i++) {
      if (a[i] == b[i]) {
        ans = ans + a[i];
      } else {
        break;
      }
    }

    return ans;
  }
};
