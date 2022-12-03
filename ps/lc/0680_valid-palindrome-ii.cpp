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
  bool validPalindrome(string s) {
    int lo = 0, hi = s.size() - 1;
    return validPalindrome(s, lo, hi, 0);
  }

  bool validPalindrome(string &s, int lo, int hi, int count) {
    if (count > 1)
      return false;
    while (lo < hi) {
      if (s[lo] == s[hi]) {
        lo++;
        hi--;
      } else {
        return validPalindrome(s, lo + 1, hi, count + 1) ||
               validPalindrome(s, lo, hi - 1, count + 1);
      }
    }
    return true;
  }
};
