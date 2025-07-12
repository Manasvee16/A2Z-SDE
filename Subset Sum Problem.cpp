class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp;
        dp.resize(sum+1, vector<int> (arr.size()+1, -1));
        int ans= helper(0, arr, sum, dp);
        return ans;
    }
    int helper(int idx, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
       
        if (sum==0)
            return 1;
        if (idx==arr.size())
            return 0;
        if (dp[sum][idx]!=-1)
            return dp[sum][idx];
            int pick=0, notpick=0;
        if (sum-arr[idx]>=0)
        {
            pick+=helper(idx+1, arr, sum-arr[idx], dp);
        }
        notpick+=helper(idx+1, arr, sum, dp);
        return dp[sum][idx]=(pick + notpick);
    }
};
