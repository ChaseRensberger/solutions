#include <iostream>
#include <string>

using namespace std;

const string target = "XMAS";

void dfs(vector<vector<char>>& graph, int i, int j, int currentLength, int& ans, int n, int m, int a, int b) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return;
	}
	if (graph[i][j] == target[currentLength]) {
		if (currentLength == target.size()-1) {
			ans++;
		} 
		else if (currentLength == 0){
			dfs(graph, i-1, j-1, currentLength+1, ans, n, m, -1, -1);
			dfs(graph, i-1, j, currentLength+1, ans, n, m, -1, 0);
			dfs(graph, i-1, j+1, currentLength+1, ans, n, m, -1, 1);
			dfs(graph, i, j-1, currentLength+1, ans, n, m, 0, -1);
			dfs(graph, i, j+1, currentLength+1, ans, n, m, 0, 1);
			dfs(graph, i+1, j-1, currentLength+1, ans, n, m, 1, -1);
			dfs(graph, i+1, j, currentLength+1, ans, n, m, 1, 0);
			dfs(graph, i+1, j+1, currentLength+1, ans, n, m, 1, 1);
		} else {
			dfs(graph, i+a, j+b, currentLength+1, ans, n, m, a, b);
		}
	}
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
			dfs(wordSearch, i, j, 0, ans, n, m, 0, 0);
		}
	}

	cout << ans << endl;
	
	return 0;
}
