// beats 44.52
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int p1 = 0; 
	   int p2 = 0;
	   int n = word1.size();
	   int m = word2.size();
	   string ans = "";

	   while (p1 < n || p2 < m) {
			ans = (p1 < n) ? ans+word1[p1] : ans; p1++;
			ans = (p2 < m) ? ans+word2[p2] : ans; p2++;
	   }

	   return ans;
    }
};
