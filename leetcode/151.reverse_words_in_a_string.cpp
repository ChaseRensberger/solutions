// Beats 100%
class Solution {
public:
	bool isAlphaNumeric(char c) {
		return (c >= 'a' && c <= 'z') ||
			   (c >= 'A' && c <= 'Z') ||
			   (c >= '0' && c <= '9');
	}
    string reverseWords(string s) {
		vector<string> words;
		string word = "";
		for (int i = 0; i < s.size(); i++) {
			if (isAlphaNumeric(s[i]))
				word += s[i];
			else if (!word.empty()){
				words.push_back(word);
				word = "";
			}
		}
		if (!word.empty()) {
			words.push_back(word);
		}
		string ans = "";
		for (int i = words.size() - 1; i >= 0; i--) {
			ans += words[i];
			if (i > 0)
				ans += " ";
		}
		return ans;
    }
};
