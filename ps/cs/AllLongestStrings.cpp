vector<string> solution(vector<string> inputArray) {
  int m(0), n(inputArray.size());
  vector<string> ans;
  for (auto &s : inputArray) {
    if (s.length() > m) {
      m = s.length();
      ans.clear();
      ans.push_back(s);
    } else if (s.length() == m) {
      ans.push_back(s);
    }
  }
  return ans;
}
