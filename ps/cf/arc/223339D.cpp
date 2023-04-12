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

void solver(int n) {
  if (n < 0)
    n = -1 * n;
  if (n / 10 > 0)
    solver(n / 10);
  cout << n % 10 << " ";
}

void solve() {
  int n;
  cin >> n;
  solver(n);
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t)
    solve(), t--;
}
