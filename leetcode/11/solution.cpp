// Beats 100%
class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1, ans = 0;

    while (r > l) {
      ans = max(min(height[l], height[r]) * (r - l), ans);
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return ans;
  }
};
