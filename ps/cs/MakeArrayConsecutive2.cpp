int solution(vector<int> statues) {
  int n(0), sz(statues.size());
  sort(begin(statues), end(statues));
  int s = statues[0];
  for (int i = 0; i < sz; i++) {
    while (statues[i] != s) {
      s++, n++;
    }
    s++;
  }
  return n;
}
// 2, 3, 6, 8
