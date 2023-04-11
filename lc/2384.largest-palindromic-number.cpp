/*
 * Problem:
 * Tags:
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

class Solution {
public:
  string largestPalindromic(string num) {
    map<char, int> mp;
    string left, right, center;
    char odd;
    int maxodd;
    for (auto &i : num) {
      mp[i]++;
    }
    for (auto &i : mp) {
      if (i.second % 2 != 0 && i.second > 1)
        i.second--;
      if (i.first != '0') {
        left += string(i.second / 2, i.first);
        right += string(i.second / 2, i.first);
      } else if (i.second >= maxodd) {
        if (i.second == maxodd && i.first > odd) {
          maxodd = i.second;
          odd = i.first;
        } else {
          maxodd = i.second;
          odd = i.first;
        }
      }
    }
    if (mp[odd] >= 1) {
      mp[odd]--;
      center += odd;
      if (mp[odd] >= 1 && odd != '0') {
        left += string(mp[odd] / 2, odd);
        right += string(mp[odd] / 2, odd);
        mp[odd] = 0;
      }
    }

    if (right.size() > 0) {
      right += string(mp[0] / 2, '0');
    }
    reverse(left.begin(), left.end());

    if (left.size() > 0) {
      left += string(mp[0] / 2, '0');
    }
    return left + center + right;
  }
};

// "7441447"
//     "7449447"
