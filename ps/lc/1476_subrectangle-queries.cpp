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

class SubrectangleQueries {
  vector<vector<int>> v;

public:
  SubrectangleQueries(vector<vector<int>> &rectangle) { v = rectangle; }

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    for (int i = row1; i <= row2; i++) {
      for (int j = col1; j <= col2; j++) {
        v[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) { return v[row][col]; }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
