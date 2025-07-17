class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      int l = 0;
      int r = n - 1;
      while (l < i && i < r) {
        int sum = nums[l] + nums[i] + nums[r];
        if (sum == 0)
          ans.push_back({nums[l], nums[i], nums[r]});
        else if (sum < 0) {
          l++;
        } else if (sum > 0) {
          r--;
        }
      }
    }
    return ans;
  }
};
