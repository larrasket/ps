vector<int> solution(vector<int> a) {
  int t1(0), t2(0), n(a.size());
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      t2 += a[i];
    else
      t1 += a[i];
  }
  return vector<int>{t2, t1};
}
