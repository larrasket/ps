/*
 * Problem: https://leetcode.com/problems/longest-mountain-in-array/
 * Tags: Array
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

#define begend(v) ((v).begin()), ((v).end())

#define begend(v) ((v).begin()), ((v).end())

class Solution {

public:
  void checkingRight(const vector<int> &arr, int &m, int &index) {
    for (; index < arr.size() - 1; index++) {
      if (arr[index + 1] < arr[index]) {
        m++;
      } else {
        break;
      }
    }
  }

  void checkingLeft(const vector<int> &arr, int &m, int &index) {
    while (index + 1 < arr.size()) {
      if (arr[index + 1] > arr[index]) {
        m++;
      } else {
        if (arr[index + 1] == arr[index]) {
          m = 0;
          return;
        } else
          break;
      }
      index++;
    }
    if (index + 1 >= arr.size()) {
      m = 0;
      return;
    }
    checkingRight(arr, m, index);
  }

  int longestMountain(vector<int> &arr) {
    int ans = 0;
    int max = 0;
    int index = 0;
    while (index + 1 < arr.size()) {
      if (arr[index] < arr[index + 1]) {
        int m = 0;
        checkingLeft(arr, m, index);
        if (m != 0 && m + 1 > max)
          max = m + 1;
      } else
        index++;
    }
    return max;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr{2, 1, 4, 7, 3, 2, 5};
  vector<int> bok{2, 2, 3};
}
