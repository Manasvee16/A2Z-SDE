#include <bits/stdc++.h>

using namespace std;
int helper(vector<int>& wt, vector<int>& val, int W, int ptr, vector<vector<int>>& dp)
{
    if (ptr==wt.size())
        return 0;
        if (dp[ptr][W]!=-1)
        return dp[ptr][W];
    int pick=0, notpick=0;
    if (W-wt[ptr]>=0)
    {
        pick=val[ptr]+helper(wt, val, W-wt[ptr], ptr+1, dp);
    }
    notpick=helper(wt, val, W, ptr+1, dp);
    return dp[ptr][W]=max(pick, notpick);
}
int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp;
    //row idx, col W, store values
    dp.resize(wt.size()+1, vector<int> (W+1, -1));
    int ptr=0;
    return helper(wt, val, W, ptr, dp);
    
}
int main() {
    vector<int>val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 6, 3};
    int W = 10;
    cout<<knapsack01(wt, val, wt.size(), W);
    return 0;
}
