/*
 * Problem: https://leetcode.com/problems/contains-duplicate/
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

bool containsDuplicate(vector<int> &nums) {
  unordered_map<int, int> hashMap;
  for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
    if (hashMap[*(iter)]++)
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
