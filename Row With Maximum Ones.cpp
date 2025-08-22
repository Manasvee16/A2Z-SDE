class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // Get number of rows (m) and number of columns (n)
        int m = mat.size(), n = mat[0].size();
        // maxOnes → stores maximum number of ones found so far (start with -1 so any valid row count replaces it)
        // rowIndex → stores the row index that has the maximum ones
        int maxOnes = -1, rowIndex = -1;
        // Loop through each row
        for (int i = 0; i < m; i++) {
            int count = 0; // count of ones in the current row
            // Loop through each column of the current row
            for (int j = 0; j < n; j++) {
                count += mat[i][j];  
                // Since mat[i][j] is either 0 or 1, adding it counts the number of ones
            }
            // If this row has more ones than the best so far
            if (count > maxOnes) {
                maxOnes = count;   // update maximum ones
                rowIndex = i;      // update row index
            }
        }
        // Return rowIndex and number of ones in that row
        return {rowIndex, maxOnes};
    }
};
//TC O(m*n)
//SC O(1)
