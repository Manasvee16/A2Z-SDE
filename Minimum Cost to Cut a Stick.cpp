class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return helper(0, n, 0, cuts.size()-1, cuts);
    }
    int helper(int left, int right, int i, int j, vector<int>& cuts)
    {
        if (i>j || left>right)
        {
            return 0;
        }
        long long int ans=INT_MAX;
        //long long int cost=0;
        for (int k=i;k<=j;k++)
        {
            long long int cost=(right-left)+helper(left, cuts[k], i, k-1, cuts)+helper(cuts[k], right, k+1, j, cuts);
            ans=min(ans, cost);
        }
        return (int)ans;
    }
};

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return helper(0, n, 0, c - 1, cuts, dp);
    }
    int helper(int left, int right, int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j || left >= right)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i; k <= j; k++) {
            if (cuts[k] <= left || cuts[k] >= right)
                continue;
            int cost = (right - left) + helper(left, cuts[k], i, k - 1, cuts, dp) + helper(cuts[k], right, k + 1, j, cuts, dp);
            ans = min(ans, cost);
        }
        if (ans==INT_MAX)
            return dp[i][j]=0;
        return dp[i][j]=ans;
    }
};
