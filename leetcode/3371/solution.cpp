// Beats 83%
class Solution {
public:
  int getLargestOutlier(vector<int> &nums) {
    int n = nums.size();
    int totalSum = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
      totalSum += nums[i];
      freq[nums[i]]++;
    }
    int ans = -INT_MAX;
    for (int i = 0; i < n; i++) {
      int outlierComplement = totalSum - nums[i];
      if (outlierComplement % 2 != 0)
        continue;
      int specialNumber = outlierComplement / 2;
      if (freq[specialNumber]) {
        if (specialNumber != nums[i] || freq[nums[i]] > 1)
          ans = max(ans, nums[i]);
      }
    }

    return ans;
  }
};
