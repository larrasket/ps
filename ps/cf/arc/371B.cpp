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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

// "It's easy", said the fox. "If the mass of a certain piece is divisible by
// two, then I can eat exactly a half of the piece. If the mass of a certain
// piece is divisible by three, then I can eat exactly two-thirds, and if the
// mass is divisible by five, then I can eat four-fifths. I'll eat a little here
// and there and make the pieces equal".

// 20 -> 10
// 15 / 5 -> 3

// 20 / 2 -> 10
// 15 / 3 -> 5
// 10 / 2 -> 55

// 14 / 8
// 14 / 2 = 7
// 8  /

void solve() {
  int a, b;
  cin >> a >> b;
  int aprime[3] = {}, bprime[3] = {};
  while (a) {
    if (!a % 5)
      a /= 5;
    else if (!a % 3)
      a /= 3;
    else if (!a % 2)
      a /= 2;
    else
      break;
  }
}

int main() {
  int t;
  cin >> t;
  while (t)
    solve(), t--;
}
