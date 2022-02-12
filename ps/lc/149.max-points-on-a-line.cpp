/*
 * Problem: https://leetcode.com/problems/max-points-on-a-line/
 * Tags: Geometry
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
#define x 0
#define y 1
using namespace std;

int crossProduct(const vector<int> &p1, const vector<int> &p2) {
  return (p1[x] * p2[y]) - (p2[x]) * (p1[y]);
}

vector<int> CovertToVector(const vector<int> &p1, const vector<int> &p2) {
  return (vector<int>){p2[x] - p1[x], p2[y] - p1[y]};
}

bool cw(const vector<int> &p1, const vector<int> &p2, const vector<int> &p3) {
  return crossProduct(CovertToVector(p1, p3), CovertToVector(p1, p2)) == 0;
}

// using collinearity, O(N^3)
// This is bad solution
// Better solve it using slope

int maxPoints(vector<vector<int>> &points) {
  int m = 0, maximum = 0, n = points.size();
  if (n <= 2)
    return n;

  maximum = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) // ignore
        continue;
      m = 2;
      for (int k = 0; k < n; k++) {
        if (k == j || k == i)
          continue;
        if ((crossProduct(CovertToVector(points[i], points[k]),
                          CovertToVector(points[i], points[j])) == 0)) {
          m++;
        }
      }
      if (m > maximum)
        maximum = m;
    }
  }
  return maximum;
}
int main() {
  vector<vector<int>> myvec = {{1, 1}, {2, 2}, {3, 3}};
  vector<vector<int>> m{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

  cout << maxPoints(m);
}
