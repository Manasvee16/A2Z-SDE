class Solution {
public:
    int mod = 1e9 + 7;
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); //row is no. of elements used, col is target sum, dp[i][j] stores the number of subsets you can form using the first i elements of the array arr that sum up to exactly j
        return helper(0, target, arr, dp);
    }
    int helper(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == arr.size()) {
            if (target==0)
                return 1;
            return 0;// base case: if target is 0, valid subset
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int pick = 0;
        if (arr[idx] <= target)
            pick = helper(idx + 1, target - arr[idx], arr, dp);
        int skip = helper(idx + 1, target, arr, dp);
        return dp[idx][target] = (pick + skip) % mod;
    }
};
