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

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int z(0);
    for (int i = 0; i < flowerbed.size(); i++) {
      bool b = i > 0 ? flowerbed[i - 1] : 0;
      bool a = i <= n - 1 ? flowerbed[i + 1] : 0;

      if ((!b && !a) && !flowerbed[i]) {
        z++;
        flowerbed[i] = 1;
      }
    }
    cout << z << endl;

    for (auto i : flowerbed) {
      cout << i << endl;
    }
    return z >= n;
  }
};
