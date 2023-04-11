/*
 * Problem: https://leetcode.com/problems/erect-the-fence/
 * Tags: Math
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
#define point vector<int>
#define sz(v) ((int)((v).size()))
#define x 0
#define y 1
using namespace std;

int orinetation(point p, point q, point r) {
  int val = (q[y] - p[y]) * (r[x] - q[x]) - (q[x] - p[x]) * (r[y] - q[y]);
  if (val == 0)
    return 0;                // collinear
  return (val > 0) ? -1 : 1; // clockwise : counterclockwise
}

vector<int> CovertToVector(vector<int> &p1, vector<int> &p2) {
  return (vector<int>){p2[x] - p1[x], p2[y] - p1[y]};
}
int crossProduct(const vector<int> p1, vector<int> p2) {
  return (p1[x] * p2[y]) - (p2[x]) * (p1[y]);
}
int direction(vector<int> p1, vector<int> p2, vector<int> p3) {
  auto temp = crossProduct(CovertToVector(p1, p3), CovertToVector(p1, p2));
  if (temp > 0)
    return 1; /* one is an alias to "return right" */
  if (temp < 0)
    return -1; /* negative one is an alias to "return left" */
  return 0;    /* alias to collinearity*/
}

bool cw(vector<int> p1, vector<int> p2, vector<int> p3) {
  return crossProduct(CovertToVector(p1, p3), CovertToVector(p1, p2)) == 0;
}
auto dis(const vector<int> &p1, const vector<int> &p2) {
  return (pow((p2[x] - p1[x]), 2) + pow((p2[y] - p1[y]), 2));
}

vector<point> convexHull(vector<point> points) {
  vector<point> hull;
  point min_y =
      *min_element(points.begin(), points.end(), [](point a, point b) {
        return make_pair(a[y], a[x]) < make_pair(b[y], b[x]);
      });
  sort(points.begin(), points.end(),
       [&min_y](const point &a, const point &b) -> int {
         int o = orinetation(min_y, a, b);
         if (o == 0) {
           return dis(min_y, a) < dis(min_y, b);
         }
         return o == -1;
       });
  for (auto iter = points.begin() + 1; iter != points.end() - 2; ++iter) {
    int o = orinetation(min_y, *iter, *(iter + 1));
    if (o == 0) {
      points.erase((iter));
    }
  }
  int n = (int)points.size();
  if (points.size() < 2)
    return hull;
  hull.push_back(points[0]);
  hull.push_back(points[1]);
  // hull.push_back(points[2]);
  for (int i = 2; i < n; i++) {
    while (orinetation(hull[hull.size() - 1], hull.back(), points[i])) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
    // cout << "ADDED: " << points[i][x] << " " << points[i][y] << endl;
  }
  return hull;
}

vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
  return convexHull(trees);
}

int main() {
  vector<vector<int>> trees{{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
  auto k = convexHull(trees);
  for (auto &mm : k) {
    cout << mm[0] << " " << mm[1] << endl;
  }
}
