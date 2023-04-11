/*
 * Problem:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/ Tags:
 * Two Pointers
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

// bad solution, slow
int removeDuplicates(vector<int> &nums) {
  for (auto iter = nums.begin(); iter < nums.end() - 2; ++iter) {
    if (*iter == *(iter + 1))
      while (*(iter + 1) == *(iter + 2) && (iter + 1 < nums.end()) &&
             (iter + 2) < nums.end())
        nums.erase(iter + 2);
  }
  return (int)nums.size();
}

int main() {
  vector<int> arr{1, 1, 1};
  //  arr.erase(arr.begin() + 2);
  cout << removeDuplicates(arr);
  for (auto &i : arr) {
    cout << i << endl;
  }
}
