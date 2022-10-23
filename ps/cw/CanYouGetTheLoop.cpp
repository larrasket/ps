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

struct Node {
  Node *getNext();
};
int getLoopSize(Node *startNode) {

  int i = 0;
  map<Node *, int> visited;
  while (startNode) {
    if (!visited.count(startNode))
      visited[startNode] = i, ++i, startNode = startNode->getNext();
    else {
      return i - visited[startNode];
    }
  }
  return 0;
}
