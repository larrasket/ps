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
  string shiftingLetters(string s, vector<int> &shifts) {
    long shift = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      s[i] = ((s[i] - 'a') + (shift + shifts[i]) % 26) % 26 + 'a';
      shift += shifts[i];
    }
    return s;
  }
};
