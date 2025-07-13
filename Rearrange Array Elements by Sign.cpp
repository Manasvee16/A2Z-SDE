class Solution 
{
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        int even=0, odd=1;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]>0)
            {
                ans[even]=nums[i];
                even=even+2;
            }
            else
            {
                ans[odd]=nums[i];
                odd=odd+2;
            }
        }
        return ans;
    }
};

//recursion
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        helper(nums, 0, ans, 0, 1);
        return ans;
    }
    void helper(vector<int>& nums, int index, vector<int>& ans, int even, int odd) {
        if (index == nums.size())
            return;
        if (nums[index] > 0) {
            ans[even] = nums[index];
            helper(nums, index + 1, ans, even + 2, odd);
        } 
        else {
            ans[odd] = nums[index];
            helper(nums, index + 1, ans, even, odd + 2);
        }
    }
};
//TC O(N)
//SC O(N)

//DP
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<bool> dp(n, false); // marks if ans[i] is filled
        helper(nums, 0, ans, 0, 1, dp);
        return ans;
    }
    void helper(vector<int>& nums, int index, vector<int>& ans, int even, int odd, vector<bool>& dp) {
        if (index == nums.size())
            return;
        if (nums[index] > 0) {
            if (!dp[even]) {
                ans[even] = nums[index];
                dp[even] = true;
            }
            helper(nums, index + 1, ans, even + 2, odd, dp);
        } 
        else {
            if (!dp[odd]) {
                ans[odd] = nums[index];
                dp[odd] = true;
            }
            helper(nums, index + 1, ans, even, odd + 2, dp);
        }
    }
};
//TC O(N)
//SC O(N)
