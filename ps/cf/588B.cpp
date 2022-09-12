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
#define sz(v) ((long long int)((v).size()))
using namespace std;
typedef pair<long long int, long long int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
typedef long long ll;

bool isLovely(long long int n) {
  long long int mx = sqrt(n);
  for (long long int i = mx; i > 1; i--) {
    if (n % (long long int)pow(i, 2) == 0) {
      return false;
    }
  }
  return true;
}

void solv(long long int n) {

  if (isLovely(n)) {
    cout << n;
    return;
  }

  long long int ans = -1;
  long long int mx = sqrt(n);
  for (long long int i = mx; i > 1; i--) {
    if (n % i == 0) {
      if (isLovely(i)) {
        ans = max(ans, i);
      }
      if (n / i != i && isLovely(n / i)) {
        ans = max(ans, n / i);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  long long int x;
  cin >> x;
  solv(x);
}
