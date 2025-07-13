class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int maximumProfit=0;
        int minStockVal=INT_MAX;
        int i=0;
        while (i<n) 
        {
            minStockVal=min(minStockVal, prices[i]); //best price to buy up to and including today
            if (prices[i]>=minStockVal)
              //If today’s price is higher than the lowest price so far, check how much profit you'd make if you sold today
              //Update maximumProfit if this is better than the previously seen profits
                maximumProfit=max(maximumProfit, prices[i]-minStockVal);
            i++;
        }
        return maximumProfit;
    }
};
//TC O(N)
//SC O(1)

//recursion
class Solution {
public:
    int helper(vector<int>& prices, int i, int minSoFar) {
        if (i == prices.size()) 
            return 0;
        int profitToday = prices[i] - minSoFar;
        int newMin = min(minSoFar, prices[i]);
        return max(profitToday, helper(prices, i + 1, newMin));
    }
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        return helper(prices, 1, prices[0]);
    }
};

//DP
class Solution {
public:
    int helper(vector<int>& prices, int i, int minSoFar, vector<int>& dp) {
        if (i == prices.size()) 
            return 0;
        if (dp[i] != -1) 
            return dp[i];
        int profitToday = prices[i] - minSoFar;
        int newMin = min(minSoFar, prices[i]);
        return dp[i] = max(profitToday, helper(prices, i + 1, newMin, dp));
    }
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        int n = prices.size();
        vector<int> dp(n, -1); //dp[i] stores the maximum profit achievable starting from day i onward, assuming we already know the minimum stock price encountered so far
        return helper(prices, 1, prices[0], dp);
    }
};
