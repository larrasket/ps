// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <iostream>
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int starti = 1, startn = n;
    int m = -1;
    if (n == 1)
      return 1;
    while (starti <= startn) {
      m = starti + (startn - starti) / 2;
      bool isM = isBadVersion(m);
      if ((m == 1 && isM) || (isM && m == n)) {
        return m;
      }
      bool beforeM = isBadVersion(m - 1);
      if (isM && !beforeM) {
        return m;
      }
      if (isM && beforeM) {
        startn = m;
        continue;
      }
      starti = m + 1;
    }
    return m;
  }
};
