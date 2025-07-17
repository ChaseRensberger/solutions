class Solution {
public:

    string encode(vector<string>& strs) {
		string encodedString = "";
		for (string str : strs) {
			encodedString += to_string(str.size()) + "#" + str;
		}
		return encodedString;
    }

    vector<string> decode(string s) {
		vector<string> ans;
		
		int i = 0;
		while (i < s.size()) {
			int j = i;
			while (s[j] != '#') {
				j++;
			}
			int length = stoi(s.substr(i, j-i));
			string stringToAdd = s.substr(j+1, length);
			ans.push_back(stringToAdd);
			i = j+1+length;
		}
		return ans; 
    }
};
