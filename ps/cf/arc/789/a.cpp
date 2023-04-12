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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int solve(vector<int> &arr, bool &zero, bool &dplct) {
  if (zero)
    return arr.size() - 1;
  if (dplct)
    return arr.size();
  return arr.size() + 1;
}

int main() {
  cout << "FUCK";
  int t, tmp;
  cin >> t;
  bool dplct = false, zero = 0;
  while (t) {
      vector<int> arr;
    map<int, int> m;
    int ln;
    cin >> ln;
    while (ln) {
      cin >> tmp;
      if (!tmp) {
        zero = 1;
      }
      m[tmp]++;
      arr.push_back(tmp);
      ln--;
    }
    for (auto &i : m) {
      if (i.second > 1) {
        dplct = true;
        break;
      }
    }
    cout << solve(arr, zero, dplct) << endl;
    t--;
  }
}
