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
#include <unordered_set>
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int searching(vector<int> arr, int x) {
  int l = 0, r = arr.size(), mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  if (arr[mid] > x)
    return mid - 1;
  return mid;
}

int main() {
  typedef pair<pair<int, int>, pair<int, int>> struch;
  struch mypari;
  mypari.first.first = 2;
  mypari.first.second = 2;
  mypari.second.first = 2;
  mypari.second.second = 2;
  pair<pair<int, int>, pair<int, int>> lol;
  lol.first.first = 2;
  lol.first.second = 2;
  lol.second.first = 2;
  lol.second.second = 1;

  map<int, int> orji, oo;
  orji[2] = 52;
  orji[1] = 52;
  oo[2] = 52;
  oo[1] = 53;
  set<map<int, int>> qr;
  qr.emplace(oo);
  cout << (oo == orji);
}
