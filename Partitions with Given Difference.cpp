class Solution {
  public:
    int mod = 1e9 + 7;

    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        // If (sum + d) is odd, we can't split it evenly
        if ((sum + d) % 2 != 0) 
            return 0;
        int target = (sum + d) / 2;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); //row is idx of element, col is target, dp[i][j] stores the number of subsets that can be formed from the first i elements of the array that sum up to exactly j
        return helper(0, target, arr, dp);
    }
    int helper(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == arr.size()) {
            if (sum==0)
                return 1;
            return 0;
        }
        if (dp[idx][sum] != -1) 
            return dp[idx][sum];
        int include = 0, exclude = 0;
        if (sum >= arr[idx])
            include = helper(idx + 1, sum - arr[idx], arr, dp);
        exclude = helper(idx + 1, sum, arr, dp);
        return dp[idx][sum] = (include + exclude) % mod;
    }
};
