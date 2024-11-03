// Beats 100%
class Solution {
public:
	const vector<char> vowels = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

	bool isVowel(char c) {
		for (char vowel : vowels) {
			if (c == vowel)
				return true;
		}
		return false;
	}
    string reverseVowels(string s) {
		int n = s.size();
		int l = 0;
		int r = n - 1;
		// IceCreAm
		// AceCreIm
		while (l < r) {
			while (!isVowel(s[l]) && l < r)
				l++;
			while (!isVowel(s[r]) && l < r)
				r--;
			
			char temp = s[l];
			s[l] = s[r];
			s[r] = temp;
			l++;
			r--;
		}
		
		return s;
    }
};
