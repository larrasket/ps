/*
 * Problem: https://leetcode.com/problems/search-a-2d-matrix/
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

int searching(vector<vector<int>> matrix, int x) {
  int l = 0, r = matrix.size() - 1, mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (matrix[mid][0] == x)
      return mid;
    if (matrix[mid][0] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  if (matrix[mid][0] > x)
    return mid - 1;
  return mid;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();
  // find column to search
  auto i = searching(matrix, target);
  if (i < 0)
    return 0;
  return binary_search(begend(matrix[i]), target);
}
int main() {
  vector<vector<int>> k{{1}};
  cout << searchMatrix(k, 2);
}
