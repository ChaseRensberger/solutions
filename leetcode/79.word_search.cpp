class Solution {
public:
	bool dfs(vector<vector<char>>& board, int n, int m, int i, int j, string word) {
			
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)	{
				if (target == board(i, j)) {
					return dfs(board, i, j, word.substr(1, word.size()-1));
				}
			}
		}
		return false;
	}
    bool exist(vector<vector<char>>& board, string word) {
		int n = board.size();
		int m = board[0].size();
		int target = word[0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)	{
				if (target == board(i, j)) {
					return dfs(board, n, m, i, j, word.substr(1, word.size()-1));
				}
			}
		}
		return false;
    }
};
