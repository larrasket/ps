/*
 * Problem: https://leetcode.com/problems/count-asterisks/
 * Tags: String
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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
int countAsterisks(string s) {
  int rs;
  bool f;
  for (auto &i : s) {
    if (i == '|')
      f = !f;
    if (!f && i == '*')
      rs++;
  }
  return rs;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
