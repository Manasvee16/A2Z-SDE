class Solution {
public:
    int countPaths(int i, int j, vector<vector<int>>& grid, int m, int n) {
        // Out of bounds or obstacle
        if (i >= m || j >= n || grid[i][j] == 1)
            return 0;
        // Reached destination
        if (i == m - 1 && j == n - 1)
            return 1;
        // Explore right and down
        int right = countPaths(i, j + 1, grid, m, n);
        int down = countPaths(i + 1, j, grid, m, n);
        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return countPaths(0, 0, obstacleGrid, m, n);
    }
};

class Solution {
public:
    int countPaths(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        // Out of bounds or obstacle
        if (i >= m || j >= n || grid[i][j] == 1)
            return 0;
        // Reached destination
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = countPaths(i, j + 1, grid, m, n, dp);
        int down = countPaths(i + 1, j, grid, m, n, dp);
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); //number of paths from (i, j) to the destination
        return countPaths(0, 0, obstacleGrid, m, n, dp);
    }
};
