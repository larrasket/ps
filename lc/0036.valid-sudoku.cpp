/*
 * Problem: https://leetcode.com/problems/valid-sudoku/
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
void iteratefunction(std::vector<std::vector<std::string>> board) {
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      for (int tempi = i; tempi < i + 3; tempi++) {
        for (int tempj = j; tempj < j + 3; tempj++) {
          cout << board[tempi][tempj] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;
  }
}

bool isValidSudoku(vector<vector<char>> &board) {
  for (int i = 0; i < 9; i++) {
    map<char, bool> mymap;
    for (int j = 0; j < 9; j++) {
      if (board[j][i] != '.') {
        if (mymap[board[j][i]] == 0)
          mymap[board[j][i]] = 1;
        else
          return 0;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    map<char, bool> mymap;
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        if (mymap[board[i][j]] == 0)
          mymap[board[i][j]] = 1;
        else
          return 0;
      }
    }
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      map<char, bool> mymap;
      for (int tempi = i; tempi < i + 3; tempi++) {
        for (int tempj = j; tempj < j + 3; tempj++) {
          if (board[tempi][tempj] != '.') {
            if (mymap[board[tempi][tempj]] == 0) {
              mymap[board[tempi][tempj]] = 1;
            } else
              return 0;
          }
        }
      }
    }
  }
  return 1;
}

int main() {
  vector<vector<string>> k = {{"8", "3", ".", ".", "7", ".", ".", ".", "."},
                              {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                              {".", "9", "8", ".", ".", ".", ".", "6", "."},
                              {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                              {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                              {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                              {".", "6", ".", ".", ".", ".", "2", "8", "."},
                              {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                              {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  // iteratefunction(k);
}
