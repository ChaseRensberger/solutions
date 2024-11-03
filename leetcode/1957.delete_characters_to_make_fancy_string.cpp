// Beats 58%
class Solution {
public:
    string makeFancyString(string s) {
		int n = s.size();
		string ans;
		ans += s[0];
		char curr_char = s[0];
		int curr_char_count = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == curr_char) {
				curr_char_count++;
			} else {
				curr_char = s[i];
				curr_char_count = 1;
			}

			if (curr_char_count < 3) {
				ans += curr_char;	
			}
		}
		return ans;
    }
};
