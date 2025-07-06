#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums, int i, int j, int minm, vector<vector<int>>& dp)
{
    if (i==j)
        return 0;
    if (dp[i][j]!=-1)
        return dp[i][j];
    for (int k=i;k<=j-1;k++)
    {
        int steps=helper(nums, i,k, minm, dp)+helper(nums, k+1, j, minm, dp)+(nums[i-1]*nums[k]*nums[j]); //TC (2^N * N) recursion
        //dp o(n^2)dp,*n(for loop)
         minm=min(minm, steps);
    }
    return dp[i][j]=minm;
}
int matrixMultiplication(vector<int>& nums){
            //your code goes here
            vector<vector<int>> dp;
            dp.resize(nums.size()+1, vector<int> (nums.size()+1, -1));
            int i=1,j=nums.size()-1;
            return helper(nums, i, j, INT_MAX, dp);
    	}
int main() {
    vector<int> nums = {10, 15, 20, 25};
    cout<<matrixMultiplication(nums);
    return 0;
}
