class Solution 
{
public:
    int uniquePaths(int m, int n) 
    { 
        return countPaths(0, 0, m, n); 
    }
    int countPaths(int i, int j, int m, int n) 
    {
        // Out of bounds
        if (i >= m || j >= n)
            return 0;
        // Destination reached
        if (i == m - 1 && j == n - 1)
            return 1;
        // Move down + Move right
        return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
    }
};
//TC O(2^n+m)
//SC o(m+n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);
    }

    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // Out of bounds
        if (i >= m || j >= n) 
            return 0;
        // Destination reached
        if (i == m - 1 && j == n - 1) 
            return 1;
        if (dp[i][j] != -1) 
            return dp[i][j];
        return dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
    }
};
//TC O(m*n)
//SC O(m*n+m+n)
