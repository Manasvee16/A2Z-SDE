class Solution {
public:
    int LongestBitonicSequence(int n, vector<int>& nums) {
        int maxLen = 0;
        for (int peak = 0; peak < n; ++peak) 
        { //Try every index as the peak of the bitonic sequence.
            int inc = lis(nums, peak, -1);      // strictly increasing up to peak (inclusive)
            int dec = lds(nums, peak, -1);      // strictly decreasing from peak (exclusive)
            if (inc > 1 && dec > 1) {           // must strictly increase and decrease
                maxLen = max(maxLen, inc + dec - 1); //We subtract 1 because the peak element is counted in both inc and dec
            }
        }
        return maxLen;
    }
    int lis(vector<int>& nums, int idx, int prevIdx) {
        if (idx < 0) return 0;
        int take = 0, notTake = 0;
        if (prevIdx == -1 || nums[idx] < nums[prevIdx])
            take = 1 + lis(nums, idx - 1, idx);
        notTake = lis(nums, idx - 1, prevIdx);
        return max(take, notTake);
    }
    int lds(vector<int>& nums, int idx, int prevIdx) {
        if (idx >= nums.size()) return 0;
        int take = 0, notTake = 0;
        if (prevIdx == -1 || nums[idx] < nums[prevIdx])
            take = 1 + lds(nums, idx + 1, idx);
        notTake = lds(nums, idx + 1, prevIdx);
        return max(take, notTake);
    }
};

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int>& nums) {
        int maxLen = 0;
        // Initialize DP tables with -1
        vector<vector<int>> dpLIS(n + 1, vector<int>(n + 1, -1));
        /*Rows → Current index we are considering in the array (from 0 to n).
          Columns → Index of the previously chosen element (-1 means nothing picked yet, so we shift by +1 to store at index 0).
          dpLIS[idx][prevIdx + 1] = Maximum length of increasing subsequence starting at idx, where last element chosen was at prevIdx.*/
        vector<vector<int>> dpLDS(n + 1, vector<int>(n + 1, -1));
        /*Rows → Current index from where we want to start decreasing subsequence.
          Columns → Index of the previously included element in decreasing chain.
          dpLDS[idx][prevIdx + 1] = Maximum length of decreasing subsequence starting at idx, where previous element used was at prevIdx.
          We use prevIdx + 1 because prevIdx can be -1*/
        for (int peak = 0; peak < n; ++peak) {
            int inc = lis(nums, peak, -1, dpLIS);  // increasing until peak
            int dec = lds(nums, peak, -1, dpLDS);  // decreasing from peak
            if (inc > 1 && dec > 1) {
                maxLen = max(maxLen, inc + dec - 1);  // subtract 1 to avoid double-counting peak
            }
        }
        return maxLen;
    }
    int lis(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx < 0) 
            return 0;
        if (dp[idx][prevIdx + 1] != -1) 
            return dp[idx][prevIdx + 1];
        int take = 0, notTake = 0;
        if (prevIdx == -1 || nums[idx] < nums[prevIdx])
            take = 1 + lis(nums, idx - 1, idx, dp);
        notTake = lis(nums, idx - 1, prevIdx, dp);
        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
    int lds(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx >= nums.size()) 
            return 0;
        if (dp[idx][prevIdx + 1] != -1) 
            return dp[idx][prevIdx + 1];
        int take = 0, notTake = 0;
        if (prevIdx == -1 || nums[idx] < nums[prevIdx])
            take = 1 + lds(nums, idx + 1, idx, dp);
        notTake = lds(nums, idx + 1, prevIdx, dp);
        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
};
