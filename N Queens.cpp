class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> cols(n); // cols[i] = column index of queen in row i
        // Generate all permutations (each row gets a queen in a unique column)
        for (int i = 0; i < n; i++) 
            cols[i] = i;
        do {
            // Use helper to check diagonals 
            if (isValid(cols, n)) {
                // Build the board
                vector<string> board(n, string(n, '.'));
                for (int i = 0; i < n; i++) {
                    board[i][cols[i]] = 'Q';
                }
                ans.push_back(board);
            }
        } while (next_permutation(cols.begin(), cols.end()));
        return ans;
    }
    // Check for diagonal conflicts
    bool isValid(vector<int>& cols, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) == abs(cols[i] - cols[j])) {
                    return false; // same diagonal
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string row(n, '.');
        for (int i=0;i<n;i++)
        {
            board.push_back(row); //create the board
        }
        findAns(0, ans, board, n); //start with first col
        return ans;
    }
    void findAns(int idx,  vector<vector<string>>& ans, vector<string> board, int n)
    {
        if (idx==n)
        {
            ans.push_back(board);
            return;
        }
        for (int i=0;i<n;i++)
        { //idx=col, i=row
            
            if (isSafe(i, idx, n, board))
            {
                board[i][idx]='Q';
            findAns(idx+1, ans, board, n);
            board[i][idx]='.';
            }
        }
    }
    bool isSafe(int row, int col, int n, vector<string>& board)
    {
        int duprow=row, dupcol=col;
        for (int i=dupcol;i>=0;i--)
        { //row
            if (board[duprow][i]=='Q')
                return false;
        }
        for (int i=duprow, j=dupcol;i>=0 && j>=0;i--,j--)
        {//upper diagonal (↗️ opp)
            if (board[i][j]=='Q')
                return false;
        }
        for (int i=duprow, j=dupcol;i<n && j>=0;j--,i++)
        {//lower diagonal (↙️)
            if (board[i][j]=='Q')
                return false;
        }
        return true;
    }
};
//TC O(N^2)
