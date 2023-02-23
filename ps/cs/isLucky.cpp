bool solution(int n) {
  int c(0), t = n, l(0), r(0), i(0);

  while (t != 0) {
    t /= 10;
    c++;
  }

  bool s;
  while (n != 0) {
    i++;
    int j = n % 10;
    n /= 10;
    if (i > c / 2) {
      l += j;
    } else {
      r += j;
    }
  }

  return l == r;
}
