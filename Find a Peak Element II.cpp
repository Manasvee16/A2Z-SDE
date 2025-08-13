class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int top = 0, bottom = m - 1;
        while (top <= bottom) {
            int midRow = top + (bottom - top) / 2;
            // Find max element in midRow
            int maxCol = 0;
            for (int j = 1; j < n; ++j) {
                if (mat[midRow][j] > mat[midRow][maxCol]) {
                    maxCol = j;
                }
            }
            // Compare with top and bottom neighbors
            int up = (midRow > 0) ? mat[midRow - 1][maxCol] : -1;
            int down = (midRow < m - 1) ? mat[midRow + 1][maxCol] : -1;
            if (mat[midRow][maxCol] > up && mat[midRow][maxCol] > down) {
                return {midRow, maxCol}; // Found a peak
            } 
            else if (down > mat[midRow][maxCol]) {
                top = midRow + 1; // Go down
            } 
            else {
                bottom = midRow - 1; // Go up
            }
        }
        return {-1, -1}; // Should never reach here if input has at least one peak
    }
};
