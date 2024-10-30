// Can be improved, probably doesn't need a heap
class Solution {
public:
    string reorganizeString(string s) {
		// k is the size of the language
		// n is length of s
		unordered_map<char, int> freq;
		int n = s.size();
		priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
		string result = "";
		for (char c : s) {
			freq[c]++;
		}
		// freq[c] n+1/2
		for (auto val : freq) { // O(klogk) to build heap since k elements and log k to insert
			if (val.second > (n+1)/2) {
				return "";
			}
			maxHeap.push({val.second, val.first});
		}

		while (maxHeap.size() >= 2) {
			auto [f1, c1] = maxHeap.top(); maxHeap.pop();
			auto [f2, c2] = maxHeap.top(); maxHeap.pop();
			
			result += c1;
			result += c2;

			if (--f1>0) maxHeap.push({f1, c1});
			if (--f2>0) maxHeap.push({f2, c2});
		}

		if(!maxHeap.empty()) result += maxHeap.top().second;

		return result;
    }
};
