/*
 * Problem: https://www.lintcode.com/problem/415/
 * Tags: Array
 */

#include <algorithm>
#include <array>
#include <cctype>
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
  /**
   * @param s: A string
   * @return: Whether the string is a valid palindrome
   */
  bool isPalindrome(string s) {
    s.erase(remove_if(begend(s),
                      [](auto const &x) -> bool {
                        if (isdigit(x))
                          return false;
                        return !isalpha(x);
                      }),
            s.end());
    transform(begend(s), s.begin(), ::toupper);
    string p = s;
    reverse(begend(p));
    return p == s;
  }
};
