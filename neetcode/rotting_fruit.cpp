class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0, time = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          fresh++;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (fresh > 0 && !q.empty()) {
      int initialQueueSize = q.size();
      for (int i = 0; i < initialQueueSize; i++) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int j = 0; j < directions.size(); j++) {
          int rowWithDirection = row + directions[j][0];
          int colWithDirection = col + directions[j][1];

          if (rowWithDirection < 0 || rowWithDirection >= n ||
              colWithDirection < 0 || colWithDirection >= m ||
              grid[rowWithDirection][colWithDirection] != 1)
            continue;

          grid[rowWithDirection][colWithDirection] = 2;
          q.push({rowWithDirection, colWithDirection});
          fresh--;
        }
      }
      time++;
    }
    return fresh == 0 ? time : -1;
  }
};
