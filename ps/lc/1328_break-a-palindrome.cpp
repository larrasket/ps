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
  string breakPalindrome(string palindrome) {
    int n = palindrome.size(), m = n / 2;
    bool odd = n % 2 == 0 ? 0 : 1;
    if (n == 1)
      return "";
    for (int i = 0; i < n; i++) {
      if (palindrome[i] > 'a' && (!odd || i != m)) {
        palindrome[i] = 'a';
        return palindrome;
      }
    }

    for (int i = 0; i < n; i++) {
      if (palindrome[i] > 'b' && (!odd || i != m)) {
        palindrome[i] = 'b';
        return palindrome;
      }
    }

    palindrome[n - 1] = 'b';
    return palindrome;
  }
};
