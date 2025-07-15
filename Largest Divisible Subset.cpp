class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        vector<int> check;
        sort(nums.begin(), nums.end());
        helper(nums, ans, check, 0, -1);
        return ans;
    }
    void helper(vector<int>& nums, vector<int>& ans, vector<int>& check, int idx, int lastidx) {
        if (idx == nums.size()) {
            if (ans.size()<check.size())
                ans=check;
            return;
        }
        if (lastidx==-1 || nums[idx]%nums[lastidx]==0)
        {
            check.push_back(nums[idx]);
            helper(nums, ans, check, idx+1, idx);
            check.pop_back();
        }
        helper(nums, ans, check, idx + 1, lastidx);
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        /*row: the current index in the nums array we're considering
          Column: the index of the last element we selected in our subset (converted from -1 to 0 for array indexing)
          dp[idx][lastIndex] stores the maximum length of the largest divisible subset that can be formed starting from index idx with the element at lastidx being the last selected element.*/
        vector<int> result = helper(nums, 0, -1, dp);
        return result;
    }
    vector<int> helper(vector<int>& nums, int idx, int lastidx, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            return {};
        }
        int lastIndex = lastidx + 1; // Convert -1 to 0 for indexing
        if (dp[idx][lastIndex] != -1) {
            // We know the max length from this state, now reconstruct
            int maxLen = dp[idx][lastIndex];
            // Try taking current element first
            if (lastidx == -1 || nums[idx] % nums[lastidx] == 0) {
                vector<int> takeResult = helper(nums, idx + 1, idx, dp);
                if (takeResult.size() + 1 == maxLen) {
                    takeResult.insert(takeResult.begin(), nums[idx]);
                    return takeResult;
                }
            }    
            // Otherwise skip current element
            return helper(nums, idx + 1, lastidx, dp);
        }
        vector<int> takeResult;
        vector<int> skipResult;
        // Try taking current element
        if (lastidx == -1 || nums[idx] % nums[lastidx] == 0) {
            takeResult = helper(nums, idx + 1, idx, dp);
            takeResult.insert(takeResult.begin(), nums[idx]);
        }
        // Try skipping current element
        skipResult = helper(nums, idx + 1, lastidx, dp);
        // Choose the longer subset
        if (takeResult.size()>skipResult.size())
            vector<int> result=takeResult;
        vector<int> result =  skipResult;
        dp[idx][lastIndex] = result.size();
        return result;
    }
};
