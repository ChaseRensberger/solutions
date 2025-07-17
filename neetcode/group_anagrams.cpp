class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> keyWithStrings;
		for (string s : strs) {
			vector<int> freq(26, 0);
			for (char c : s) {
				freq[c - 'a']++;
			}
			string key = to_string(freq[0]);
			for (int i = 1; i < 26; i++) {
				key += ',' + to_string(freq[i]);
			}
			keyWithStrings[key].push_back(s);
		}
		vector<vector<string>> ans;
		for (pair<string, vector<string>> pair : keyWithStrings) {
			ans.push_back(pair.second);
		}
		return ans;
    }
};
