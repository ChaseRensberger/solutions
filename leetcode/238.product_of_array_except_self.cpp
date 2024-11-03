// Beats 100%
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
 		vector<int> result(n, 0);
		int sum = 1;
		int zeroCount = count(nums.begin(), nums.end(), 0);
		if (zeroCount == 1) {
			int zeroLocation = -1;
			for (int i = 0; i < n; i++) {
				if (nums[i] != 0)
					sum *= nums[i];
				else
					zeroLocation = i;
			}
			result[zeroLocation] = sum;
			return result;
		} else if (zeroCount > 1) {
			return result;
		}

		for (int i = 0; i < n; i++) {
			sum *= nums[i];
		}
		for (int i = 0; i < n; i++) {
			result[i] = sum / nums[i];
		}
		return result;
    }
};
