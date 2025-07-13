class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int n = nums.size();
        int lp = 1; //product of subarray starting from the left.
        int rp = 1; //product of subarray starting from the right.
        int ans = INT_MIN; //max product found so far
        for(int i=0 ; i<n ; i++)
        { //traverse the array from both ends simultaneously
        //multiply with current elements
            lp*=nums[i];
            rp*=nums[n-i-1];
            ans = max({ans,lp,rp});
            if(lp==0) 
                lp=1;
            if(rp==0) 
                rp=1;
        }
        return ans;
    }
};
/*In product subarray problems, a negative number may turn into a positive product if multiplied by another negative.
So, it's crucial to consider prefixes from both left and right ends.*/

//recursion
class Solution {
public:
    pair<int, int> helper(int i, vector<int>& nums, int& globalMax) {
        if (i == 0) {
            globalMax = nums[0];
            return {nums[0], nums[0]};
        }
        pair<int, int> prev = helper(i - 1, nums, globalMax);
        int maxEndingHere = max({nums[i], nums[i] * prev.first, nums[i] * prev.second});
        int minEndingHere = min({nums[i], nums[i] * prev.first, nums[i] * prev.second});
        globalMax = max(globalMax, maxEndingHere);
        return {maxEndingHere, minEndingHere};
    }
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        helper(nums.size() - 1, nums, globalMax);
        return globalMax;
    }
};
//TC O(2^n)
//SC O(n)

//DP
class Solution {
public:
    int helper(int i, vector<int>& nums, vector<pair<int,int>>& dp, int& globalMax) {
        if (i == 0) {
            globalMax = nums[0];
            return dp[0] = {nums[0], nums[0]}, nums[0];
        }
        if (dp[i].first != INT_MIN) return dp[i].first;
        helper(i - 1, nums, dp, globalMax); // ensure dp[i-1] is computed
        int maxPrev = dp[i - 1].first;
        int minPrev = dp[i - 1].second;
        int curMax = max({nums[i], nums[i] * maxPrev, nums[i] * minPrev});
        int curMin = min({nums[i], nums[i] * maxPrev, nums[i] * minPrev});
        dp[i] = {curMax, curMin};
        globalMax = max(globalMax, curMax);
        return curMax;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n, {INT_MIN, INT_MIN}); // stores {maxProdEndingAtI, minProdEndingAtI}
        int globalMax = nums[0];
        for (int i = 0; i < n; ++i) {
            helper(i, nums, dp, globalMax);
        }
        return globalMax;
    }
};
//TC O(N)
//SC O(N)
