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
  int prnt(int x, vector<int> &prnt) {
    while (prnt[x] != x) {
      x = prnt[x];
    }
    return x;
  }
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> un(edges.size() + 1);
    vector<int> res(2);
    for (int i = 0; i < un.size(); i++) {
      un[i] = i;
    }
    for (int i = 0; i < edges.size(); i++) {
      int x = prnt(edges[i][0], un);
      int y = prnt(edges[i][1], un);
      if (x != y) {
        un[y] = x;
      } else {
        res[0] = edges[i][0], res[1] = edges[i][1];
      }
    }
    return res;
  }
};
