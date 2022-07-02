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

using namespace std;

string originalDigits(string s) {
  /*
  ** zero // unique z
  ** two  // unique w
  ** four // uinque u
  ** six  // unique x
  ** eight //unique g
  **
  **
  ** one  // o is an id, delete zero & two & four
  ** three // t is an id, delete eight, two
  ** five // f is an id, delete four
  ** seven // s is an id, delete 6
  ** nine // i is an id, delete 5, 6 , 8
  */
  vector<int> v(10, 0);
  for (auto &i : s)
    switch (i) {
    case 'z':
      v[0]++;
      break;
    case 'w':
      v[2]++;
      break;
    case 'u':
      v[4]++;
      break;
    case 'x':
      v[6]++;
      break;
    case 'g':
      v[8]++;
      break;
      //  odd
    case 'o':
      v[1]++;
      break;
    case 't':
      v[3]++;
      break;
    case 'f':
      v[5]++;
      break;
    case 's':
      v[7]++;
      break;
    case 'i':
      v[9]++;
      break;
    }

  v[1] = v[1] - v[0] - v[2] - v[4];
  v[3] = v[3] - v[8] - v[2];
  v[5] -= v[4];
  v[7] -= v[6];
  v[9] = v[9] - v[5] - v[6] - v[8];
  string ans;
  int x = 0;
  for (auto &i : v) {
    auto st = std::to_string(x);
    x++;
    while (i)
      ans += st, i--;
  }
  return ans;
}

int main() { std::cout << originalDigits("fviefuro") << std::endl; }
