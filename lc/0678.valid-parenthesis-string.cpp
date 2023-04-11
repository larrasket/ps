/*
 * Problem: https://leetcode.com/problems/valid-parenthesis-string/
 * Tags: Stack
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

bool isValid(string &s) {
  stack<char> paren;
  for (char &c : s) {
    switch (c) {
    case '.':
      break;
    case '(':
    case '{':
    case '[':
      paren.push(c);
      break;
    case ')':
      if (paren.empty() || paren.top() != '(')
        return false;
      else
        paren.pop();
      break;
    case '}':
      if (paren.empty() || paren.top() != '{')
        return false;
      else
        paren.pop();
      break;
    case ']':
      if (paren.empty() || paren.top() != '[')
        return false;
      else
        paren.pop();
      break;
    default:; // pass
    }
  }
  return paren.empty();
}
bool checker(string &s, int n, int index = 0) {
  if (index > n)
    return 0;
  if (index == n) {
    return isValid(s);
  }
  if (s[index] == '*') {
    s[index] = ')';
    if (checker(s, n, index + 1))
      return 1;
    s[index] = '(';
    if (checker(s, n, index + 1))
      return 1;
    s[index] = '.';
    if (checker(s, n, index + 1))
      return 1;
  } else {
    if (checker(s, n, index + 1))
      return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string i = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))("
             "((((())*)))()))(()((*()*(*)))(*)()";
  string p = "EQTQT"
             "QTQT";
  cout << p << endl;
}
