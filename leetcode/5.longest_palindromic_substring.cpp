// beats 50%
class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.size();
		int dp[n][n];
		memset(dp, 0, sizeof(dp));
		int ans_i = 0, ans_j = 0;

		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}

		for (int i = 0; i < n-1; i++) {
			if (s[i]==s[i+1]) {
				dp[i][i+1] = 1;
				ans_i = i;
				ans_j = i+1;
			}
		}

		for (int diff = 2; diff < n; diff++) {
			for (int i = 0; i < n - diff; i++) {
				int j = i + diff;
				if (s[i] == s[j] && dp[i+1][j-1]) {
					dp[i][j] = 1;
					ans_i = i;
					ans_j = j;
				}
			}
		}
		
		return s.substr(ans_i, ans_j-ans_i+1);

    }
};
