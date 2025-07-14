class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        return helper(nums, 0, sum / 2);
    }
    bool helper(vector<int>& nums, int ptr, int target) {
        if (target == 0)
            return true;
        if (ptr == nums.size())
            return false;
        // Try picking the current element if it doesn't overshoot target
        if (nums[ptr] <= target) {
            if (helper(nums, ptr + 1, target - nums[ptr]))
                return true;
        }
        // Or skip the current element
        return helper(nums, ptr + 1, target);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if (sum%2!=0)
            return false;
        vector<vector<int>> dp;
        dp.resize(nums.size()+1, vector<int> ((sum/2)+1, -1));
      /*Rows Represents all possible ptr values i.e., index of the current number we’re deciding to pick or not pick.
        Columns Represents all possible target values we may try to reach from 0 to sum/2
        It stores the answer to Is it possible to pick a subset starting from index ptr that adds up to target?
        true (1): Yes, it's possible
        false (0): No, it's not possible*/
        return helper(nums, dp, 0, sum/2);
    }
    bool helper(vector<int>& nums, vector<vector<int>>& dp, int ptr, int target)
    {
        if (target==0)
            return true;
        if (ptr==nums.size())
            return false;
        if (dp[ptr][target]!=-1)
            return dp[ptr][target];
        bool pick=false, notpick=false;
        if (target-nums[ptr]>=0)
        {
            pick=helper(nums, dp, ptr+1, target-nums[ptr]);
        }
        notpick=helper(nums, dp, ptr+1, target);
        return dp[ptr][target]=(pick || notpick);
    }
};
