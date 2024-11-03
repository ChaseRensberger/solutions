// Beats 100%
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		// 	Input: nums = [2,1,5,0,4,6]
		// Output: true
		
		int first = INT_MAX, second = INT_MAX;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			if (nums[i] < first) {
				first = nums[i];
				continue;
			} else if (nums[i] < second && nums[i] > first) {
				second = nums[i];
				continue;
			} else if (nums[i] > first && nums[i] > second) {
				return true;
			}
		}
		return false;
    }
};
