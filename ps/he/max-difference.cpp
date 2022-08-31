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

int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    int n;
    cin >> n;
    if (!n) {
      cout << 0 << endl;
      continue;
    }
    vector<int> arr;
    while (n) {
      n--;
      int tmp;
      cin >> tmp;
      arr.push_back(tmp);
    }
    sort(begend(arr));
    if (arr.size() <= 3)
      cout << arr[arr.size() - 1] - arr[0] << endl;
    else
      cout << arr[arr.size() - 1] - arr[0] + arr[arr.size() - 2] - arr[1]
           << endl;
  }
}
