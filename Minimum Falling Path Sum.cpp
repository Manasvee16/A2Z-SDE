class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix, int n) {
        if (col < 0 || col >= n) 
            return INT_MAX;
        if (row == n - 1) 
            return matrix[row][col];
        int down = solve(row + 1, col, matrix, n);
        int leftDiagonal = solve(row + 1, col - 1, matrix, n);
        int rightDiagonal = solve(row + 1, col + 1, matrix, n);
        return matrix[row][col] + min({down, leftDiagonal, rightDiagonal});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPath = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPath = min(minPath, solve(0, j, matrix, n));
        }
        return minPath;
    }
};
//TC O(3^N)
//SC O(N)

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp) {
        if (col < 0 || col >= n) 
            return INT_MAX;
        if (row == n - 1) 
            return matrix[row][col];
        if (dp[row][col] != -1) 
            return dp[row][col];
        int down = solve(row + 1, col, matrix, n, dp);
        int leftDiagonal = solve(row + 1, col - 1, matrix, n, dp);
        int rightDiagonal = solve(row + 1, col + 1, matrix, n, dp);
        return dp[row][col] = matrix[row][col] + min({down, leftDiagonal, rightDiagonal});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); //stores the minimum falling path sum starting from cell (i, j) to the bottom
        int minPath = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPath = min(minPath, solve(0, j, matrix, n, dp));
        }
        return minPath;
    }
};
//TC O(N^2)
//SC O(N^2)+O(N)
