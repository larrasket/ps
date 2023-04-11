/*
 * Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
 * Tags: Binary Search
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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int z = matrix.size();
    for (int i = 0; i < z; i++) {
      if (binary_search(begend(matrix[i]), target))
        return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
