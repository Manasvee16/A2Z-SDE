class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return helper(arr, 0, 0, k, false);
    }
    // Add a flag to ensure we only count non-empty subsets
    bool helper(vector<int>& nums, int idx, int currSum, int k, bool taken) 
    { //taken: a flag to track if we've included at least one element
    //currSum: current sum formed by selected elements
        if (idx == nums.size()) {
            return (currSum == k && taken);
            //sum is exactly k && we have taken atleast one element
            //This avoids counting the empty subset as a valid answer
        }
        // Include current element
        if (helper(nums, idx + 1, currSum + nums[idx], k, true))
            return true;
        //As soon as either choice leads to a successful subsequence with sum == k, we can stop further exploration and return tru
        //This is short-circuiting: If one path works, there's no need to check the other
        // Exclude current element
        if (helper(nums, idx + 1, currSum, k, taken))
            return true;
        //So we're not interested in counting all such subsequences, we only care if at least one valid subsequence exists.
        return false;
    }
};
//TC O(2^N)
//SC O(N)

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> dp;
        dp.resize(n+1, vector<int> (k+1, -1)); //row=size of array, col=values of k, store=is it possible to reach k using this
        return helper(arr, 0, 0, k, false, dp);
    }
    // Add a flag to ensure we only count non-empty subsets
    bool helper(vector<int>& nums, int idx, int currSum, int k, bool taken, vector<vector<int>>& dp) 
    { //taken: a flag to track if we've included at least one element
    //currSum: current sum formed by selected elements
        if (idx == nums.size()) {
            return (currSum == k && taken);
            //sum is exactly k && we have taken atleast one element
            //This avoids counting the empty subset as a valid answer
        }
        if (currSum>k)
            return false; //pruning
        // Only memoize when a number has been taken
        if (taken && dp[idx][currSum] != -1)
            return dp[idx][currSum];
        bool include = helper(nums, idx + 1, currSum + nums[idx], k, true, dp);
        bool exclude = helper(nums, idx + 1, currSum, k, taken, dp);
        //store when a non-empty subsequence is being formed
        if (taken)
            dp[idx][currSum] = (include || exclude); //If either path leads to a valid non-empty subsequence that sums to k, return true
        //if dp stores false, then if we encounter the same state again, we don’t repeat the recursion, we just return false
        return include || exclude;
    }
};
//TC O(n*k)
//SC O(n*k)+O(n)
  //dp table+recursion stack
