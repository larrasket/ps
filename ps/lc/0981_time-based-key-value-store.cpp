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
#include <utility>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

class TimeMap {
  unordered_map<string, map<int, string>> keyTimeMap;

public:
  TimeMap() { // mp = {};
  }

  void set(string key, string value, int timestamp) {

    keyTimeMap[key][timestamp] = value;
  }
  string get(string key, int timestamp) {
    if (keyTimeMap.find(key) == keyTimeMap.end()) {
      return "";
    }

    auto it = keyTimeMap[key].upper_bound(timestamp);
    // If iterator points to first element it means, no time <= timestamp
    // exists.
    if (it == keyTimeMap[key].begin()) {
      return "";
    }

    // Return value stored at previous position of current iterator.
    return prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
