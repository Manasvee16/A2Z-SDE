class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();  
        for (int i = 0; i < m; i++) {  
            // Iterate over each row of the matrix
            int l = 0, r = n - 1;  
            // Initialize pointers for binary search on the current row
            // l = left index, r = right index
            while (l <= r) {  
                // Standard binary search loop. Continue while the search interval is valid
                int mid = l + (r - l) / 2;  
                // Find the middle index to avoid integer overflow
                if (matrix[i][mid] == target)  
                    return true;  
                // If the middle element matches target, we found it
                else if (matrix[i][mid] < target)  
                    l = mid + 1;  
                // If middle element is less than target, search the right half
                else  
                    r = mid - 1;  
                // If middle element is greater than target, search the left half
            }
        }
        return false;  
        // If all rows are searched and target is not found, return false
    }
};
//TC O(mlogn)
//SC O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns
        // Start from the top-right corner of the matrix
        int row = 0, col = n - 1;
        // Continue searching while we are inside the bounds of the matrix
        while (row < m && col >= 0) {
            // If the current element matches the target → found
            if (matrix[row][col] == target) {
                return true;
            }
            // If current element is larger than target → move left (because all elements below are even larger)
            else if (matrix[row][col] > target) {
                col--;
            }
            // If current element is smaller than target → move down (because all elements to the left are even smaller)
            else {
                row++;
            }
        }
        // If we exit the loop, target is not in the matrix
        return false;
    }
};
//Top-right or Bottom-left both work, because they give you one increasing direction and one decreasing direction. Top-left or Bottom-right don’t work, because both directions move in the same trend (both increase or both decrease), so you can’t eliminate possibilities.
