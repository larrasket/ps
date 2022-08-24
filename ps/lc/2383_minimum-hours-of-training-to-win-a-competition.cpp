/*
 * Problem:
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define begend(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
using namespace std;

class Solution {
public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int> &energy, vector<int> &experience) {
    int toadd = 0, n = energy.size(), enr = initialEnergy,
        exp = initialExperience;
    for (int i = 0; i < n; i++) {
      while (!(energy[i] < enr)) {
        toadd++;
        enr++;
      }
      enr -= energy[i];

      while (!(experience[i] < exp)) {
        toadd++;
        exp++;
      }
      exp += experience[i];
    }
    return toadd;
  }
};
