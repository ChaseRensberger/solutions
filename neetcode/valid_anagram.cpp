class Solution {
public:
    bool isAnagram(string s, string t) {
		int n = s.size(), m = t.size();
		if (n != m)
			return false;
		
		unordered_map<char, int> sf, tf;
		for (int i = 0 ; i < n; i++) {
			sf[s[i]]++;
			tf[t[i]]++;
		}
		return (sf == tf);
    }
};
