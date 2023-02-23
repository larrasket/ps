int solution(vector<int> inputArray) {
  int n = inputArray.size(), ans(INT_MIN);
  for (int i = 0; i < n - 1; i++) {
    if ((inputArray[i] * inputArray[i + 2]) > ans)
      ans = inputArray[i] * inputArray[i + 1];
  }
  return ans;
}
