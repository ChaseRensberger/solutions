// Input: cost = [1,2,1,2,1,1,1]
//  Output: 4
//  0, 0, 1,

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);

    for (int i = 2; i < n + 1; i++) {
      dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }

    return dp[n];
  }
};
