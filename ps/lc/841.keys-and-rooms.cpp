/*
 * Problem: https://leetcode.com/problems/keys-and-rooms/
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
void DFS(vector<vector<int>> &graph, vector<bool> &v, int i) {
  v[i] = 1;
  for (auto &index : graph[i]) {
    if (!v[index])
      DFS(graph, v, index);
  }
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
  vector<bool> visited(rooms.size());
  DFS(rooms, visited, 0);
  return (find(begend(visited), false) == end(visited));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
