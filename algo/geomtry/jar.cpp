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

struct p {
  int x, y;
  p(int i, int j) : x(i), y(j) {}
  p tovector(p p2) { return p(p2.x - this->x, p2.y - this->y); }
};

int crossProduct(p p1, p p2) { return (p1.x * p2.y) - (p2.x) * (p1.y); }
int direction(p p1, p p2, p p3) {
  auto temp = crossProduct(p1.tovector(p3), p1.tovector(p2));
  if (temp > 0)
    return 1; /* one is an alias to "return right" */
  if (temp < 0)
    return -1; /* negative one is an alias to "return left" */
  return 0;    /* alias to collinearity*/
}
vector<p> jar(vector<p> points) {
  vector<p> convex;

  return convex;
}

int main() {}
