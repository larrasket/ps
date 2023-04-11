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
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> of, cf;
    for (auto &i : s1) {
      of[i]++;
    }
    int i = 0, j = 0;
    while (j < s2.size() && i < j) {
      cf[s2[j]]++;

      if (cf.size() == of.size()) {
        cout << "HERE ";
        bool equal = true;
        for (auto &z : of) {
          if (z.second != cf[z.first]) {
            equal = false;
            break;
          }
        }
        if (equal)
          return 1;
      }
      if (cf.size() < of.size()) {
        j++;
      } else {
        cf[s2[i]]--;
        if (!cf[s2[i]]) {
          cf.erase(s2[i]);
        }
        i++;
      }
    }
    return false;
  }
};
