/*
 * Problem: https://leetcode.com/problems/minimum-jumps-to-reach-home/
 * Tags: Dynamic Programming
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
int r, l;
int Reach(int &Forward, int &Backward, int Position, int &Target,
          vector<int> &Forbidden, int Steps) {
  if (Position < Target) {
    if (find(begend(Forbidden), Position + Forward) == Forbidden.end())
      return Reach(Forward, Backward, Position + Forward, Target, Forbidden,
                   Steps + 1);
  } else if (Position > Target) {
    if (find(begend(Forbidden), Position - Backward) == Forbidden.end() &&
        Position - Backward >= 0)
      return Reach(Forward, Backward, Position - Backward, Target, Forbidden,
                   Steps + 1);
  }
  return Target == Position ? Steps : -1;
}
int main() {
  vector<int> f{162, 118, 178, 152, 167, 100, 40,  74,  199, 186, 26,
                73,  200, 127, 30,  124, 193, 84,  184, 36,  103, 149,
                153, 9,   54,  154, 133, 95,  45,  198, 79,  157, 64,
                122, 59,  71,  48,  177, 82,  35,  14,  176, 16,  108,
                111, 6,   168, 31,  134, 164, 136, 72,  98};

  int a = 29, b = 98, x = 80;
  cout << Reach(a, b, 0, x, f, 0);
}
