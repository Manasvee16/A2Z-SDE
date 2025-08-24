class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // 2D dp table
        return solve(0, 0, triangle, dp);
    }
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        // Base case: last row
        if (i == n - 1) 
            return triangle[i][j];
        // If already computed
        if (dp[i][j] != INT_MAX) 
            return dp[i][j];
        // Recursive relation
        int down = solve(i + 1, j, triangle, dp);
        int diag = solve(i + 1, j + 1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
};
//TC O(n^2)
//SC O(n*m)+0(n)
