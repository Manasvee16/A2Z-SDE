class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        return solve(arr, 1, n - 1);
    }
    int solve(vector<int>& arr, int i, int j) {
        // Base case: if there's only one matrix, no multiplication needed
        if (i == j) {
            return 0;
        }
        int minCost = INT_MAX; 
        // Try all possible positions to split the chain
        for (int k = i; k < j; k++) {
            // Cost to multiply matrices from i to k
            int leftCost = solve(arr, i, k);
            // Cost to multiply matrices from k+1 to j
            int rightCost = solve(arr, k + 1, j);
            // Cost to multiply the two resulting matrices
            int mergeCost = arr[i - 1] * arr[k] * arr[j];
            // Total cost for this split
            int totalCost = leftCost + rightCost + mergeCost;
            // Update minimum cost
            minCost = min(minCost, totalCost);
        }
        return minCost;
    }
};

class Solution {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
      /*Row: (start index of subchain)
      Column: (end index of subchain)
      Value Stored: Minimum number of scalar multiplications needed to compute the matrix product from index i to j (i.e., matrices Aᵢ through Aⱼ).*/
        return solve(arr, 1, n - 1, dp);
    }
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minCost = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(arr, i, k, dp);
            int right = solve(arr, k + 1, j, dp);
            int cost = arr[i - 1] * arr[k] * arr[j];
            minCost = min(minCost, left + right + cost);
        }
        return dp[i][j] = minCost;
    }
};
//TC O(n^2)dp O(n) for loop
