/*
 * Problem: https://leetcode.com/problems/rotating-the-box/
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

vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
  for (auto &j : box) {
    queue<vector<char>::iterator> em;
    for (auto iter = j.begin(); iter != j.end(); ++iter) {
      if (!em.empty() && *iter == '#') {
        // swap(iter, em.front());
        *iter = '.';
        *em.front() = '#';
        em.pop();
      } else if (*iter == '.') {
        em.push(iter);
      } else if (*iter == '*') {
        em = {};
      }
    }
  }
  int n = box.size(), m = box[0].size();
  vector<vector<char>> ans(m, vector<char>(n));
  for (int i = 0; i < n; i++) {
    reverse(begend(box[i]));
    for (int j = 0; j < m; j++) {
      ans[j][i] = box[i][j];
    }
  }
  return box;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<char>> a;
  a.push_back((vector<char>){'#', '.', '#'});

  a = rotateTheBox(a);
  for (auto k : a) {
    for (auto vk : k) {
      cout << vk << " " << endl;
    }
  }
}
