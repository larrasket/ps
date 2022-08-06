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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

vector<int> ans;

class Solution {
private:
  vector<int> dfs(vector<vector<int>> &list, vector<bool> &visited, int i) {
    visited[i] = 1;
    ans.push_back(i);
    for (auto &e : list[i]) {
      if (!visited[e])
        dfs(list, visited, e);
    }
    return ans;
  }

  vector<int> findmother(vector<vector<int>> &adj, int &V) {
    vector<bool> visited(V, false);
    int v = 0;
    for (int i = 0; i < V; i++) {
      if (!visited[i])
        dfs(adj, visited, i), v = i;
    }
    fill(visited.begin(), visited.end(), false);
    ans = vector<int>();
    dfs(adj, visited, v);
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        return vector<int>();

    return ans;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> courses(numCourses);
    for (int i = 0; i < prerequisites.size(); i++) {
      courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    return findmother(courses, numCourses);
  }
};
