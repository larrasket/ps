/*
 * Problem: https://leetcode.com/problems/k-closest-points-to-origin/
 * Tags: geometry
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
vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  sort(begend(points), [](vector<int> lpoint, vector<int> rpoint) {
    return (pow(lpoint[x], 2) + pow(lpoint[y], 2)) <
           (pow(rpoint[x], 2) + pow(rpoint[y], 2));
  });
  return vector<vector<int>>(points.begin(), points.begin() + k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
  kClosest(points, 0);
  for (auto &i : points) {
    cout << i[0] << " " << i[1] << endl;
  }
}
