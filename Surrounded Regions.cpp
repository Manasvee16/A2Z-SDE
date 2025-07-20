class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) 
            return;
        int m = board[0].size();
        // Step 1: DFS from all 'O's on the boundary
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') 
                dfs(i, 0, board, n, m);
            if (board[i][m - 1] == 'O') 
                dfs(i, m - 1, board, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') 
                dfs(0, j, board, n, m);
            if (board[n - 1][j] == 'O') 
                dfs(n - 1, j, board, n, m);
        }
        // Step 2: Flip surrounded 'O's to 'X', and 'B's back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if (board[i][j] == 'B') 
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(int row, int col, vector<vector<char>>& board, int n, int m) {
        // Boundary and character check
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O') 
            return;
        board[row][col] = 'B'; // Temporarily mark as safe
        for (int k = 0; k < 4; ++k) {
            int newRow = row + dx[k];
            int newCol = col + dy[k];
            dfs(newRow, newCol, board, n, m);
        }
    }
};
