/*
 * Problem: https://www.lintcode.com/problem/213/?_from=collection&fromId=185
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

class Solution {
  string ans;

public:
  /**
   * @param originalString: a string
   * @return: a compressed string
   */
  string compress(const string &originalString) {
    int n = originalString.size(), count = 0;
    int i;
    for (i = 0; i < n; i++) {
      cout << originalString[i + 1] << " index " << (i + 1) << endl;
      count++;
      if (originalString[i + 1] != originalString[i])
        ans.push_back(originalString[i]), ans.append(to_string(count)),
            count = 0;
    }
    return ans.length() < originalString.length() ? ans : originalString;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution i;
  cout << i.compress("aabcccccaaa");
  // string r = "eqe";
  // cout << r[3];
}
