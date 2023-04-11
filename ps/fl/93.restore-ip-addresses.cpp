/*
 * Problem: https://leetcode.com/problems/restore-ip-addresses/
 * Tags: Dynamic Programming
 */

#include <algorithm>
#include <array>
#include <bits/types/cookie_io_functions_t.h>
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
void solve(string &input, vector<string> &output,
           int NumberOfCurrentSegments = 0, string IP = "", string Segment = "",
           int index = 0) {
  cout << index << endl;
  if (index > input.length())
    return;
  if (Segment.length() > 1 && Segment[0] == '0')
    return;
  if (NumberOfCurrentSegments && stoi(Segment) > 255)
    return;
  // if (NumberOfCurrentSegments == 5 && IP.length() != input.length() + 3)
  //   return;
  if (IP.length() == input.length() + 3) {
    auto k = IP;
    k.pop_back();
    output.push_back(k);
    return;
  }
  solve(input, output, NumberOfCurrentSegments + 1, IP + Segment + '.',
        string(1, input[index]), index + 1);
  solve(input, output, NumberOfCurrentSegments, IP, Segment + input[index],
        index + 1);
}

vector<string> restoreIpAddresses(string s) {
  vector<string> ans;
  solve(s, ans, 0, "", string(1, s[0]), 1);
  return ans;
}
int main() {
  string i = "25525511135";
  auto o = restoreIpAddresses(i);
  for (auto &n : o) {
    cout << n << endl;
  }
  // string k = "";
  // k = k + '2';
  // cout << k.length();
  // o
}
