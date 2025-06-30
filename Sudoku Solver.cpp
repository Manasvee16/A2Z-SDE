class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        board[i][j] = c;
                        if (isValid(board, i, j)) {
                            if (solve(board)) 
                                return true; // move to next empty cell
                        }
                        board[i][j] = '.'; // backtrack
                    }
                    return false; // no valid digit possible here
                }
            }
        }
        return true; // solved
    }
    // Validate row, col, and 3x3 box 
    bool isValid(vector<vector<char>>& board, int row, int col) {
        char val = board[row][col];
        // Check row
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == val)
                return false;
        }
        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == val)
                return false;
        }
        // Check 3x3 box (your helper logic)
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == val)
                    return false;
            }
        }
        return true;
    }
};
