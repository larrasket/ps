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
  int strStr(string haystack, string needle) {
    char f = needle[0];
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i < n; i++) {
      if (haystack[i] == f) {
        int t(i), j(0);
        for (j = 0; j < m && t < n; j++, t++) {
          if (haystack[t] != needle[j])
            break;
        }
        if (j == m - 1)
          return i;
      }
    }
    return -1;
  }
};
