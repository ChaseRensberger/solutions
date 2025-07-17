class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					q.push({i, j});
				}
			}
		}
		
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			
			vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
			for (int i = 0; i < directions.size(); i++) {
				int r = row + directions[i][0];
				int c = col + directions[i][1];

				if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX) {
					continue;
				}
				grid[r][c] = grid[row][col] + 1;
				q.push({r, c});
			}
		}
    }
};
