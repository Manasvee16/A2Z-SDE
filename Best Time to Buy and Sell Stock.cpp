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
