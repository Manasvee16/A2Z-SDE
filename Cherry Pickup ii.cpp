class Solution {
public:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, int m, int n) {
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return 0;
        int result = 0;
        result += (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        if (row == m - 1) 
            return result;
        int maxCherries = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                maxCherries = max(maxCherries, solve(row + 1, col1 + d1, col2 + d2, grid, m, n));
            }
        }
        return result + maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(0, 0, n - 1, grid, m, n);
    }
};
