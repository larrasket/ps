/*
 * Problem:
 * https://leetcode.com/contest/weekly-contest-280/problems/count-operations-to-obtain-zero/
 * Tags: Numbers
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num1 = 10, num2 = 10;
  int op = 0;
  while (num1 != 0 && num2 != 0) {
    if (num1 >= num2) {
      num1 -= num2;
      op++;
    } else {
      num2 -= num1;
      op++;
    }
  }
  cout << op << endl;
  return op;
}
