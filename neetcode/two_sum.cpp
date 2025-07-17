class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> comp;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			comp[target - nums[i]] = i;
		}

		for (int i = 0; i < n; i++) {
			if (comp.find(nums[i]) != comp.end() && i != comp[nums[i]]) {
				return {i, comp[nums[i]]};
			}
		}

		return {};
    }
};
