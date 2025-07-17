class Solution {
public:
  unordered_map<int, int> dp = {{1, 1}, {2, 2}};
  int climbStairs(int n) {
    if (n < 3) {
      return dp[n];
    }
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    dp[n] = ans;
    return ans;
  }
};
