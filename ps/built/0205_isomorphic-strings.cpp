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
  bool isIsomorphic(string s, string t) {
    map<char, int> m1, m2;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      m1[s[i]]++;
      m2[t[i]]++;
    }

    for (int i = 0; i < n; i++) {
      if (m1[s[i]] != m2[t[i]])
        return false;
    }
    return true;
  }
};
