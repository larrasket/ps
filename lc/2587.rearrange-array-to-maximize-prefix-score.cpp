class Solution {
public:
  int maxScore(vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<>());
    long long m = 0;
    long long p = 0;
    for (int i = 0; i < nums.size(); i++) {
      p += nums[i];
      if (p > 0)
        m++;
    }

    return m;
  }
};
