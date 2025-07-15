class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return helper(0, 1, prices);
    }
    int helper(int i, int canBuy, vector<int>& prices) {
        if (i == prices.size()) 
            return 0;
        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, 0, prices);
            int skip = helper(i + 1, 1, prices);
            return max(buy, skip);
        } 
        else {
            int sell = prices[i] + helper(i + 1, 2, prices);  
            int skip = helper(i + 1, 0, prices);
            return max(sell, skip);
        }
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        /*Row = Day i (0-based index of the day)
        Column = canBuy	Either 1 or 0:
        `1` → you can buy a stock  
        `0` → you have already bought and now you can sell        
        dp[i][1] → Max profit starting from day i if you're allowed to buy
        dp[i][0] → Max profit starting from day i if you're holding a stock and must sell next*/
        return helper(0, 1, prices, dp);
    }
    int helper(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) 
            return 0;
        if (dp[i][canBuy] != -1) 
            return dp[i][canBuy];
        int profit = 0;
        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, 0, prices, dp); 
            int skip = helper(i + 1, 1, prices, dp);            
            profit = max(buy, skip);
        } 
        else {
            int sell = prices[i] + helper(i + 1, 1, prices, dp);
            int skip = helper(i + 1, 0, prices, dp);           
            profit = max(sell, skip);
        }
        return dp[i][canBuy] = profit;
    }
};
