// Beats 100%
class Solution {
public:
  int scoreOfString(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += abs(static_cast<int>(s[i]) - static_cast<int>(s[i - 1]));
    }
    return ans;
  }
};
