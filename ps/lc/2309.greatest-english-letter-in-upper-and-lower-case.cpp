/*
 * Problem:
 * https://leetcode.com/contest/weekly-contest-298/problems/greatest-english-letter-in-upper-and-lower-case/
 * Tags: Strings
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <functional>
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

string greatestLetter(string s) {
  string p = "", r = "";
  map<char, bool> lr, up;
  for (auto &k : s) {
    if (islower(k))
      lr[k] = true;
    else
      up[k] = true;
    if (lr[tolower(k)] && up[toupper(k)])
      p += toupper(k);
  }
  sort(begend(p));
  if (p.size() == 0)
    return "";
  r += p[p.size() - 1];
  return r;
}

int main() { cout << greatestLetter("arRAzFif"); }
