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
  int part(vector<int> &arr, int s, int e) {
    int p = arr[e];
    int i = s - 1;
    for (int j = s; j <= e - 1; j++) {
      if (p > arr[j]) {
        i++;
        swap(arr[j], arr[i]);
      }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
  }
  void srt(vector<int> &arr, int s, int e) {
    if (s < e) {
      int p = part(arr, s, e);
      srt(arr, s, p - 1);
      srt(arr, p + 1, e);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    srt(nums, 0, nums.size() - 1);
    return nums;
  }
};
