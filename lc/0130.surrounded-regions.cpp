/*
 * Problem: https://leetcode.com/problems/surrounded-regions/
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
public:
  int mr, md;
  map<pair<int, int>, bool> visited;
  void capture(int i, int j, vector<vector<char>> &board, bool &vld) {
    if (!(i < md && i >= 0) || !(j < mr && j >= 0) || vld == 0 ||
        board[i][j] != 'O')
      return;
    if (i == md - 1 || j == mr - 1 || j == 0 || i == 0) {
      vld = 0;
      return;
    } else
      board[i][j] = 'X';
    visited[{i, j}] = 1;
    // up
    capture(i - 1, j, board, vld);
    // down
    capture(i + 1, j, board, vld);
    // left
    capture(i, j + 1, board, vld);
    // right
    capture(i, j - 1, board, vld);
  }

  void solve(vector<vector<char>> &board) {
    md = board.size();
    mr = board[0].size();
    for (int i = 0; i < md; i++) {
      for (int j = 0; j < mr; j++) {
        bool v = 1;
        if (board[i][j] == 'O' && !visited[{i, j}]) {
          auto cp = board;
          capture(i, j, cp, v);
          if (v)
            board = cp;
        }
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
