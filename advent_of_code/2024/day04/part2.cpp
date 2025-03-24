#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> freq = {{'M', 1}, {'S', 1}};

void explore(vector<vector<char>>& graph, int i, int j, int& ans, int n, int m) {
	if (graph[i][j] != 'A' || i-1 < 0 || j-1 < 0 || i+1 >= n || j+1 >= m)
		return;
	
	unordered_map<char, int> one;
	unordered_map<char, int> two;

	one[graph[i-1][j-1]]++;
	one[graph[i+1][j+1]]++;
	
	two[graph[i-1][j+1]]++;
	two[graph[i+1][j-1]]++;

	if (one == freq && two == freq)
		ans++;
}

int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<char>> wordSearch;
	string line;
	while (getline(cin, line)) {
		wordSearch.push_back({});
		for (char c : line) {
			wordSearch[wordSearch.size()-1].push_back(c);
		}
	}
	
	int n = wordSearch.size();
	int m = wordSearch[0].size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			explore(wordSearch, i, j, ans, n, m);
		}
	}

	cout << ans;
	
	return 0;
}
