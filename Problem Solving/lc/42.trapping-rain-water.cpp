/*
 * Problem: https://leetcode.com/problems/trapping-rain-water/
 * Tags:
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
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

int trap(vector<int> &height) {
  int ans = 0, LastElev = 0, LastBigElev = 0, LastTracked, tempadd;
  int n = height.size();
  for (int i = 1; i < n; i++) {
    if (height[i] > height[i - 1]) {
      int tempi = i - 1;
      int MaxToAdd = height[i] - height[i - 1];
      if (height[i] >= height[LastBigElev]) {
        LastTracked = tempi;
        while (tempi != LastBigElev) {
          if (height[tempi] >= height[LastTracked]) {
            LastTracked = tempi;

            MaxToAdd = height[LastBigElev] - height[tempi];
          }
          tempadd = (height[LastBigElev] - height[tempi]);
          ans += (tempadd > MaxToAdd) ? MaxToAdd : tempadd;
          tempi--;
          cout << ans << " " << i << " " << n << endl;
        }
        LastBigElev = i;
      } else {
        LastTracked = tempi;
        while (tempi >= 0 && height[i] > height[tempi]) {
          tempadd = height[i] - height[tempi];
          ans += (tempadd > MaxToAdd) ? MaxToAdd : tempadd;
          LastTracked = tempi;
          tempi--;
          cout << ans << "-" << i << " " << n << endl;
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<int> h = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2,
                   7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
  vector<int> k = {5, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
  cout << trap(h) << endl;
  ;
}
