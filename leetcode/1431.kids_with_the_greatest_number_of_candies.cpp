// beats 100%
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int n = candies.size();
 		int max_candy = candies[0];
		for (int i = 1; i < n; i++) {
			max_candy = max(max_candy, candies[i]);
		}
		vector<bool> ans(n, false);
		for (int i = 0; i < n; i++) {
			ans[i] = (candies[i] + extraCandies >= max_candy);
		}
		return ans;
    }
};
