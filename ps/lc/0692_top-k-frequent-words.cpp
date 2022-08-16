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
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> freq;
    for (auto w : words) {
      freq[w]++;
    }

    auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    typedef priority_queue<pair<string, int>, vector<pair<string, int>>,
                           decltype(comp)>
        my_priority_queue_t;
    my_priority_queue_t pq(comp);

    for (auto w : freq) {
      pq.emplace(w.first, w.second);
      if (pq.size() > k)
        pq.pop();
    }

    vector<string> output;
    while (!pq.empty()) {
      output.insert(output.begin(), pq.top().first);
      pq.pop();
    }
    return output;
  }
};
