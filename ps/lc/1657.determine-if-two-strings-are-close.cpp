/*
 * Problem:  https://leetcode.com/problems/determine-if-two-strings-are-close/
 * Tags: String
 */

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
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))

int countDistinct(string s) {

  unordered_map<char, int> m;

  for (int i = 0; i < s.length(); i++) {
    m[s[i]]++;
  }

  return m.size();
}

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() == word2.length())
      return false;
    sort(begend(word1));
    sort(begend(word2));
    if (word1 == word2)
      return true;
    int w1 = countDistinct(word1);
    int w2 = countDistinct(word2);
    if (w1 != w2)
      return false;
    string c1 = word1, c2 = word2;
    c1.erase(std::unique(c1.begin(), c1.end()), c1.end());
    c2.erase(std::unique(c2.begin(), c2.end()), c2.end());
    if (c1 != c2)
      return false;

    vector<int> d1, d2;
    for (int i = 0; i < c1.length(); i++) {
      int o = count(begend(word1), c1[i]);
      d1.push_back(o);
    }
    for (int i = 0; i < c2.length(); i++) {
      int o = count(begend(word2), c2[i]);
      d2.push_back(o);
    }
    sort(begend(d1));
    sort(begend(d2));
    if (d1 == d2)
      return true;
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution l;
  l.closeStrings("wqrwqr", "qrqwtq");
}
