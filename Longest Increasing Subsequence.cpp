class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, INT_MIN);
    }
    int helper(vector<int>& nums, int idx, int picked) {
        int skip = 0, pick = 0;
        if (idx == nums.size())
            return 0;
        if (picked==INT_MIN) {
            pick = 1 + helper(nums, idx + 1, nums[idx]);
            skip = helper(nums, idx + 1, picked);
        } 
        else {
            if (picked<nums[idx]) {
                pick = 1 + helper(nums, idx + 1, nums[idx]);
            }
            skip = helper(nums, idx + 1, picked);
        }
        return max(pick, skip);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp;
        dp.resize(nums.size()+1, vector<int> (nums.size()+1, -1)); 
        /*Row is the current index in the nums array that we are trying to decide whether to include or skip.
          Column is the index of the last picked element in the subsequence (shifted by +1 to handle -1 base case).
          dp[idx][pickedidx + 1] stores The length of the longest increasing subsequence that can be formed starting from index idx, given that the last picked element was at index pickedidx.*/
        return helper(nums, 0, -1, dp);
    }
    int helper(vector<int>& nums, int idx, int pickedidx, vector<vector<int>>& dp) {
        int skip = 0, pick = 0;
        if (idx == nums.size())
            return 0;
        if (dp[idx][pickedidx+1]!=-1)
            return dp[idx][pickedidx+1];
        if (pickedidx==-1) {
            pick = 1 + helper(nums, idx + 1, idx, dp);
           
        } 
        else {
            if (nums[pickedidx]<nums[idx]) {
                pick = 1 + helper(nums, idx + 1, idx, dp);
            }
        }
         skip = helper(nums, idx + 1, pickedidx, dp);
        return dp[idx][pickedidx+1]=max(pick, skip);
    }
};
