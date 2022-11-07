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
  vector<int> partitionLabels(string s) {
    vector<int> ans;
    map<char, bool> unique;
    map<char, int> count;
    int zeros(0), size = 0;
    for (auto &i : s)
      count[i]++;

    for (int i = 0; i < s.size(); i++) {
      unique[s[i]] = 1, size++, count[s[i]]--;
      if (!count[s[i]])
        zeros++;
      if (zeros == unique.size())
        zeros = 0, unique.clear(), ans.push_back(size), size = 0;
    }

    return ans;
  }
};
