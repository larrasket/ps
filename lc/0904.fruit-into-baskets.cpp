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
  int totalFruit(vector<int> &tree) {

    int n = tree.size();
    unordered_map<int, int> hm;

    int i = 0, j = 0, res = INT_MIN;
    for (i = 0; i < n; i++) {
      hm[tree[i]]++;

      while (j < n && hm.size() > 2) {
        hm[tree[j]]--;
        if (hm[tree[j]] == 0)
          hm.erase(tree[j]);
        j++;
      }
      res = max(res, i - j + 1);
    }

    return res == INT_MIN ? (hm.size() > 0 ? n : 0) : res;
  }
};
