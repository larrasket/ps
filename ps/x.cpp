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
  std::vector<int> mv{1, 10, 19, 20, 23};
  cout << mv[searching(mv, 20)];
}
