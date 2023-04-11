class Solution {
public:
  int vowelStrings(vector<string> &words, int left, int right) {
    int ans(0);
    for (int i = left; i <= right; i++) {
      char c = words[i][0];
      char ce = words[i][words[i].size() - 1];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        if (ce == 'a' || ce == 'e' || ce == 'i' || ce == 'o' || ce == 'u') {

          ans++;
        }
    }
    return ans;
  }
};
