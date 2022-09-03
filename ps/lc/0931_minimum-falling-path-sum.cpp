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
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[i][j] +=
            min({matrix[i - 1][max(j - 1, 0)], matrix[i - 1][j],
                 matrix[i - 1][min((int)matrix.size() - 1, j + 1)]});
      }
    }
    return *min_element(begend(matrix[matrix.size() - 1]));
  }
};
