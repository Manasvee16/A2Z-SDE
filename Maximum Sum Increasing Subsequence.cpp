class Solution {
public:
    int helper(vector<int>& arr, int prevIdx, int currIdx, vector<vector<int>>& dp) {
        if (currIdx == arr.size())
            return 0;
        if (dp[prevIdx + 1][currIdx] != -1)
            return dp[prevIdx + 1][currIdx];
        int take = 0, notTake = 0;
        //Take current element if increasing
        if (prevIdx == -1 || arr[currIdx] > arr[prevIdx]) {
            take = arr[currIdx] + helper(arr, currIdx, currIdx + 1, dp);
        }
        //Don't take current element
        notTake = helper(arr, prevIdx, currIdx + 1, dp);
        return dp[prevIdx + 1][currIdx] = max(take, notTake);
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
      /*prevIdx+1	Row: previous index used in the increasing subsequence. Offset by 1 to accommodate -1 as a valid "no previous element" state.
        currIdx	Column: the current index being considered.
        dp[prevIdx+1][currIdx] stores the maximum sum of an increasing subsequence that starts at currIdx, given that the previous index in the subsequence was prevIdx.*/
        return helper(arr, -1, 0, dp);
    }
};
