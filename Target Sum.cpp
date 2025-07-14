class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, nums, target, 0);
    }
    int helper(int idx, vector<int>& nums, int target, int sum)
    {
        if (target==sum && idx==nums.size())
        {
            return 1;
        }
        else if (idx==nums.size())
        {
            return 0;
        }
        return helper(idx+1, nums, target, sum+nums[idx])+helper(idx+1, nums, target, sum-nums[idx]);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        // The sum can range from -totalSum to +totalSum
        // So offset it by totalSum to make all indices positive
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1)); //dp[idx][sum + offset] stores No of ways to reach the target using elements from index idx to the end, having accumulated sum.
        return helper(0, 0, nums, target, dp, totalSum);
    }
    int helper(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (idx == nums.size()) {
            if (sum==target)
                return 1;
            return 0;
        }
        // Convert sum to offset-indexed column
        if (dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];
        int plus = helper(idx + 1, sum + nums[idx], nums, target, dp, offset);
        int minus = helper(idx + 1, sum - nums[idx], nums, target, dp, offset);
        return dp[idx][sum + offset] = plus + minus;
    }
};
