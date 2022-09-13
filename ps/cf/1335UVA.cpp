// (3,5) ---> 1
// ^  ^
// |  |
// 2  3
//
// ---
// 3  4
//
//

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
typedef long long ll;
map<int, int> th;
map<int, int> prm; // 1 = nonprime, 2 = prime

bool isprime(long long n) {
  if (n == 2 || prm[n] == 2)
    return true;
  if (n < 2 || n % 2 == 0 || prm[n] == 1)
    return false;

  prm[n] = 1;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  prm[n] = 2;
  return true;
}

void twthprime(long long n) {

  if (th[n] != 0) {
    cout << "(" << th[n] << ", " << th[n] + 2 << ")" << endl;
    return;
  }

  int i = 0;
  int first = 3;
  while (i != n) {
    if (isprime(first) && isprime(first + 2)) {
      i++;
      th[i] = first;
    }
    first += 2;
  }
  cout << "(" << first - 2 << ", " << first << ")" << endl;
}

// void solve() {}
int main() {
  int n;
  while (cin >> n)
    twthprime(n);
}
