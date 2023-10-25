#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    double ans = INT_MAX;
    int workers_length = quality.size();
    vector<pair<int, int>> workers;
    for (int i = 0; i < workers_length; i++) {
      workers.push_back({quality[i], wage[i]});
    }
    sort(workers.begin(), workers.end(),
         [](const pair<int, int> &p1, const pair<int, int> &p2) {
           double f = (double)p1.second / (double)p1.first;
           double s = (double)p2.second / (double)p2.first;
           return f < s;
         });

    for (int i = k - 1; i < workers_length; i++) {
      double captin_ratio =
          (double)workers[i].second / (double)workers[i].first;
      priority_queue<double, vector<double>, greater<double>> pq;

      for (int j = i; j >= 0; j--) {
        pq.push(captin_ratio * workers[j].first);
      }

      int t = k;
      double sum = 0;
      while (t--) {
        sum += pq.top();
        pq.pop();
      }
      if (sum < ans) {
        ans = sum;
      }
    }
    return ans;
  }
};
