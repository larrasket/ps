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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      long long sum(0), count(0);
      while (n--) {
        auto v = q.front();
        q.pop();
        count++;
        sum += v->val;
        if (v->left)
          q.push(v->left);
        if (v->right)
          q.push(v->right);
      }
      ans.push_back((double)sum / count);
    }
    return ans;
  }
};
