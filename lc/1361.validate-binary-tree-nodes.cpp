/*
 * Problem:
 * Tags:
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
  bool vldiate(vector<bool> &visited, int i, vector<int> &left,
               vector<int> right) {
    if (i == -1)
      return true;
    if (visited[i])
      return false;
    visited[i] = true;
    return vldiate(visited, left[i], left, right) &&
           vldiate(visited, right[i], left, right);
  }

public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    vector<bool> visited(n, false);
    return vldiate(visited, 0, leftChild, rightChild);
  }
};
