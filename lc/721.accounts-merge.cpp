
/* Problem: https://leetcode.com/problems/accounts-merge/
 * Tags: Graphs */

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

vector<vector<string>> _accounts = {
    {"John", "johnsmith@mail.com", "john00@mail.com"},
    {"Mary", "mary@mail.com"},
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    {"John", "johnnybravo@mail.com"}};

map<string, pair<string, vector<string>>> mymap;
map<string, bool> checkvisit;
void DFS(map<string, pair<string, vector<string>>> &xmap, string &email,
         vector<string> &temp) {
  temp.emplace_back(email);
  checkvisit[email] = 1;
  for (auto &i : xmap[email].second) {
    if (!checkvisit[i]) {
      DFS(xmap, i, temp);
    }
  }
}

// generate graph
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
  int z = accounts.size();
  for (int i = 0; i < z; i++) {
    for (int j = 1; j < accounts[i].size(); j++) {
      mymap[accounts[i][j]].first = accounts[i][0];
      for (int k = 1; k < accounts[i].size(); k++) {
        if (accounts[i][j] != accounts[i][k]) {
          mymap[accounts[i][j]].second.emplace_back(accounts[i][k]);
          mymap[accounts[i][k]].second.emplace_back(accounts[i][j]);
        }
      }
    }
  }
  vector<vector<string>> ans; for (auto &i : accounts) {
    vector<string> temp;
    for (int j = 1; j < i.size(); j++) {
      if (!checkvisit[i[j]]) {
        temp.emplace_back(i[0]);
        DFS(mymap, i[j], temp);
      }
    }
    if (!temp.empty()) {
      sort(temp.begin() + 1, temp.end());
      ans.emplace_back(temp);
    }
  }
  return ans;
}

int main() { accountsMerge(_accounts); }
