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
  map<char, string> mp{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };
  map<char, bool> used;
  int n;

  void backtrack(vector<string> &res, string &dgts, int st,
                 string current = "") {
    if (current.size() == n) {
      res.push_back(current);
      return;
    }
    for (int i = 0; i < mp[dgts[st]].size(); i++) {
      current.push_back(mp[dgts[st]][i]);
      backtrack(res, dgts, st + 1, current);
      current.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    n = digits.size();
    if (!n)
      return res;
    backtrack(res, digits, 0);
    return res;
  }
};
