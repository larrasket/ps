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
private:
  vector<vector<bool>> visted;
  int li, lj;
  void solve(vector<vector<char>> &bord, int i, int j) {
    if (j < 0 || i < 0 || i >= li || j >= lj)
      return;
    if (visted[i][j])
      return;
    solve(bord, i, j + 1); // left
    // right
    solve(bord, i, j - 1);
    // up
    solve(bord, i + 1, j);
    // down
    solve(bord, i - 1, j);
  }

public:
  int countBattleships(vector<vector<char>> &board) {
    int ans = 0;
    li = board.size(), lj = board[0].size();
    visted = vector<vector<bool>>(li, vector<bool>(lj, 0));
    std::cout << visted.size() << std::endl;
    std::cout << visted[0].size() << std::endl;

    for (int i = 0; i < li; i++) {
      for (int j = 0; j < lj; j++) {
        if (board[i][j] == 'X' && !visted[i][j])
          solve(board, i, j);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<char>> x = {
      {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
  std::cout << s.countBattleships(x) << std::endl;
}
