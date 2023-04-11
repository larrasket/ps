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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int i = digits.size() - 1;
    int r = digits[i] + 1;
    if (r < 10) {
      digits[i]++;
    } else {
      digits[i] = 0;
      i--;
      while (i >= 0) {
        r = digits[i] + 1;
        if (r < 10) {
          digits[i]++;
          break;
        }
        digits[i] = 0;
        i--;
      }
      if (i < 0) {
        digits.insert(digits.begin(), 1, 1);
      }
    }
    return digits;
  }
};
