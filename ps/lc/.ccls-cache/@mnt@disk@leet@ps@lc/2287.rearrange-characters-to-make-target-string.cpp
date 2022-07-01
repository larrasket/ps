#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
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
using namespace std;
#include <iomanip>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int rearrangeCharacters(string s, string target) {
  map<char, int> mfr, dfr;
  int ins = INT_MAX;
  if (!s.length())
    return 0;
  for (auto &i : s) {
    mfr[i]++;
  }
  for (auto &i : target) {
    dfr[i]++;
  }
  for (auto &i : target) {
    ins = min(ins, (mfr[i] - dfr[i] < 0 ? 0 : mfr[i] - dfr[i]));
  }
  return ins;
}
