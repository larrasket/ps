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
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

class Solution {
  int n, m;
  map<char, bool> mp;

public:
  bool exist(vector<vector<char>> &board, string word) {
    n = board.size(), m = board[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    for (auto &i : word) {
      mp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          if (solve(board, word, i, j, "", visited))
            return 1;
        }
      }
    }
    return 0;
  }
  bool solve(vector<vector<char>> &board, string &word, int i, int j,
             string current, vector<vector<bool>> &visited) {
    if (i < 0 || i >= n)
      return false;
    if (j < 0 || j >= m)
      return false;
    if (!mp[board[i][j]])
      return false;
    if (visited[i][j])
      return 0;
    current += board[i][j];
    visited[i][j] = 1;
    if (current.find(word) != string::npos)
      return true;
    if (solve(board, word, i, j + 1, current, visited))
      return true;
    if (solve(board, word, i, j - 1, current, visited))
      return true;
    if (solve(board, word, i + 1, j, current, visited))
      return true;
    if (solve(board, word, i - 1, j, current, visited))
      return true;
    return false;
  }
};
