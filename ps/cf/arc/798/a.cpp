/*
 * Problem: A. Lex String
 * Tags: Two Pointers
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

string solve(string &s1, string &s2, int &n, int &m, int &k) {
  int i = 0, j = 0;
  int sr = 0;
  int sl = 0;
  sort(begend(s1));
  sort(begend(s2));
  string c;
  char t;
  while (m != 0 && n != 0) {
    if (sr >= k) {
      c += (s1[i]), i++, n--, sr = 0, sl++;
      continue;
    } else if (sl >= k) {
      c += (s2[j]), j++, m--, sl = 0, sr++;
      continue;
    }
    if (s1[i] < s2[j])
      c += (s1[i]), i++, n--, sl++, sr = 0;

    else
      c += (s2[j]), j++, m--, sr++, sl = 0;
  }
  return c;
}

int main() {
  int c, n, m, k;
  string s1, s2;
  cin >> c;
  while (c) {
    cin >> n >> m >> k;
    cin >> s1 >> s2;
    cout << solve(s1, s2, n, m, k) << endl;
    c--;
  }
}
