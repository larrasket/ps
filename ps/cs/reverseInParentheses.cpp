int solve(string &s, int p) {
  int n = s.size(), i;
  for (i = p; i < n; i++) {
    if (s[i] == '(') {
      i = solve(s, i + 1);
      continue;
    }
    if (s[i] == ')') {
      reverse(s.begin() + p, s.begin() + i);
      break;
    }
  }
  return i;
}
string solution(string inputString) {
  int n = inputString.size();
  for (int i = 0; i < n; i++) {
    if (inputString[i] == '(') {
      i = solve(inputString, i + 1);
    }
  }
  inputString.erase(remove(inputString.begin(), inputString.end(), '('),
                    inputString.end());
  inputString.erase(remove(inputString.begin(), inputString.end(), ')'),
                    inputString.end());
  return inputString;
}
