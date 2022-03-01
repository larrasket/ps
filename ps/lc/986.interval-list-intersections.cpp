/*
 * Problem: https://leetcode.com/problems/interval-list-intersections/
 * Tags: Two Pointers
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

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                         vector<vector<int>> &secondList) {
  int i = 0, j = 0, nf = firstList.size(), ns = secondList.size();
  vector<vector<int>>ans;
  while (i < nf && j < ns) {
    int s = max(firstList[i][0], secondList[j][0]);
    int e = min(firstList[i][1], secondList[j][1]);
    if (s <= e) ans.push_back({s,e});
    if(firstList[i][1] < secondList[j][1]) i++; else j++;
 }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
