/*
 * Problem: https://leetcode.com/problems/simplify-path/
 * Tags: string
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

string simplifyPath(string path) {

  for (auto it = path.begin(); it + 1 != path.end(); ++it) { // remove
    while (*it == '/' && *(it + 1) == '/')
      path.erase(it);
  }

  string::iterator last, beforelast;
  for (auto it = path.begin(); it + 1 != path.end(); ++it) {
    if (*(it) == '/') {
      beforelast = last;
      last = it;
    }
    if (*it == '.') {
      if (*(it + 1) == '/' && *(it - 1) != '.') {
        path.erase(it);
        path.erase(it);
      } else if (*(it + 1) == '.') {
        // path.erase(last, it + 2);
      }
    }
  }
  if (*(path.end() - 1) == '/')
    path.pop_back();
  return path;
}

int main() {
  ios_base::sync_with_stdio(false);
  string path = "/../";
  cout << simplifyPath(path);
  cin.tie(NULL);
}
