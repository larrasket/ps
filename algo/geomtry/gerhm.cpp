#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
using namespace std;

struct p {
  int x, y;
  p(int i, int j) : x(i), y(j) {}
  p CovertToVector(p p2) const { return {p2.x - this->x, p2.y - this->y}; }
  bool operator==(const p &p2) {
    return make_pair(this->x, this->y) == make_pair(p2.x, p2.y);
  }
};

int crossProduct(p p1, p p2) { return (p1.x * p2.y) - (p2.x) * (p1.y); }
int direction(p p1, p p2, p p3) {
  auto temp = crossProduct(p1.CovertToVector(p3), p1.CovertToVector(p2));
  if (temp > 0)
    return 1; /* one is an alias to "return right" */
  if (temp < 0)
    return -1; /* negative one is an alias to "return left" */
  return 0;    /* alias to collinearity*/
}

bool cw(p p1, p p2, p p3) {
  return crossProduct(p1.CovertToVector(p3), p1.CovertToVector(p2)) == 0;
}
auto dis(const p &p1, const p &p2) {
  return (pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

vector<p> convexHull(vector<p> input) {
  vector<p> convex;
  auto lefest = min_element(begend(input), [](p a, p b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x); // O(N)
  });
  convex.push_back(*lefest);
  iter_swap(lefest, input.begin());
  sort(input.begin() + 1, input.end(),
       [&lefest](const p &a, const p &b) -> int {
         int d = direction(*lefest, a, b);
         if (d == 0) {
           if (dis(a, *lefest) > dis(b, *lefest))
             return -1;
           else
             return 1;
         }
         return d < 0;
       });
  auto i = input.begin() + 1;
  vector<p> neoInput;
  while (i != input.end() - 1) {
    if ((cw(*lefest, *i, *(i + 1)))) {
      i++;
      continue;
    }
    neoInput.push_back(*i);
    i++;
  }

  neoInput.push_back(*(input.end() - 1));
  convex.push_back(neoInput[0]);
  convex.push_back(neoInput[1]);
  convex.push_back(neoInput[2]);
  for (int i = 3; i < neoInput.size(); i++) {

    int d = direction(convex[convex.size() - 2], convex[convex.size() - 1],
                      neoInput[i]);

    while (convex.size() > 1 && d < 0)
      convex.pop_back();
    convex.push_back(neoInput[i]);
  }
  return convex;
}

int main() {
  vector<p> po{{0, 0}, {7, 0}, {3, 1}, {5, 2}, {9, 6}, {5, 5}, {3, 3}, {1, 4}};
  auto ans = convexHull(po);
  for (auto &k : ans) {
    cout << k.x << " " << k.y << endl;
  }
}
