/*
 * Problem: https://www.lintcode.com/problem/1882/
 * Tags: Array
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
public:
  /**
   * @param A: an array of integers
   * @param B: an array of integers
   * @return: return a integer indicating the number of fair indexes.
   */
  int CountIndexes(vector<int> &A, vector<int> &B) {
    // Write your code here.
    int s = 0, t = 0;
    int count = 0;
    int N = A.size();
    int suma = 0, sumb = 0;
    for (int j = 0; j < N; j++) {
      suma += A[j];
      sumb += B[j];
    }
    if (suma != sumb)
      return 0;
    else {
      for (int i = 0; i < N; i++) {
        s = s + A[i];
        t = t + B[i];
        if ((s == t) && ((suma - s) == s) && ((sumb - t) == t) &&
            (i != N - 1)) {
          count += 1;
        }
      }
    }
    return count;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
