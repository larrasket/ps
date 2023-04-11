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

// Definition for a Node.
// class Node {
// public:
//   int val;
//   Node *next;
//   Node *random;

//   Node(int _val) {
//     val = _val;
//     next = NULL;
//     random = NULL;
//   }
// };

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return head;
    map<Node *, Node *> mp;
    Node *nHead = new Node(head->val);
    mp[head] = nHead;
    auto tmp = head;
    auto ntmp = nHead;
    tmp = tmp->next;
    while (tmp) {
      ntmp->next = new Node(tmp->val);
      ntmp = ntmp->next;
      mp[tmp] = ntmp;
      tmp = tmp->next;
    }
    tmp = head;
    ntmp = nHead;

    while (tmp) {
      ntmp->random = mp[tmp->random];
      tmp = tmp->next;
      ntmp = ntmp->next;
    }

    return nHead;
  }
};
