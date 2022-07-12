/*
 * Problem:
 * https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/ Tags:
 * Numbers
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
  int countOdds(int low, int high) { return (high + 1) / 2 - low / 2; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
