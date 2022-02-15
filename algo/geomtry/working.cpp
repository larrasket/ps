#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
#define x 0
#define y 1
#define point vector<int>
using namespace std;

class lol {
public:
  lol();
  virtual ~lol();
};
int orinetation(point p, point q, point r) {
  int val = (q[y] - p[y]) * (r[x] - q[x]) - (q[x] - p[x]) * (r[y] - q[y]);
  if (val == 0)
    return 0;                // collinear
  return (val > 0) ? -1 : 1; // clockwise : counterclockwise
}

double dis(point p, point q) {
  return pow(p[x] - q[x], 2) + pow(p[y] - q[y], 2) * 1.0;
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
  hull.push_back(points[2]);
  for (int i = 2; i < n; i++) {
    while (orinetation(hull[hull.size() - 2], hull.back(), points[i])) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }
  return hull;
}
