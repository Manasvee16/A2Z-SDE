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

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // Find the row that has the maximum number of 1s. Return {rowIndex, numberOfOnes}.
        vector<int> ans(2, INT_MIN); // ans[0] = row index of the row with maximum 1s, ans[1] = maximum number of 1s found so far, Initialize with INT_MIN so any real value will be greater.        
        int n = mat.size(), m = mat[0].size();
        // Iterate through each row
        for (int i = 0; i < mat.size(); i++)
        {
            sort(mat[i].begin(), mat[i].end()); // Sorting ensures that all 0s come before all 1s in the row. This makes it easier to binary search the first occurrence of 1.            
            int sum = m - helper(mat[i], 1, m-1); // returns the index of the first element >= 1 (i.e., first 1).
            // If index = k, then number of 1s = totalColumns - k = m - k.
            if (sum > ans[1])
            {
                // If this row has more 1s than the previous max:
                ans[0] = i;     // update row index
                ans[1] = sum;   // update maximum number of 1s
            }
        }
        return ans; // Final result: [rowIndex, maximumNumberOfOnes]
    }
   int helper(vector<int>& mat, int target, int end)
    {
        // performs binary search to find the first index where mat[index] >= target. This is the "lower bound" search.

        int sum = mat.size(); //(default if 1 not found).
        int start = 0; //left pointer
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mat[mid] >= target)
            {
                sum = mid;
                end = mid - 1;  // Move left to check if there is an earlier occurrence of 1.
            }
            else
            {
                start = mid + 1; // If mat[mid] < 1 → move right to find first 1.
            }
        }
        return sum;  // Returns index of first 1 if found, else mat.size() (no 1 present).
    }
};
//TC: O(n * m log m)
//SC: O(log m)
