class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        return helper(0, W, val, wt);
    }
    int helper(int idx, int capacity, vector<int>& val, vector<int>& wt) {
        // Base case: if all items considered or capacity is 0
        if (idx == val.size() || capacity == 0)
            return 0;
        // If item can be included
        if (wt[idx] <= capacity) {
            // 2 choices: include or exclude
            int include = val[idx] + helper(idx + 1, capacity - wt[idx], val, wt);
            int exclude = helper(idx + 1, capacity, val, wt);
            return max(include, exclude);
        } 
        else {
            // If item too heavy, skip it
            return helper(idx + 1, capacity, val, wt);
        }
    }
};

/*idx → current item index
capacity → current remaining weight
dp[idx][capacity] stores the maximum profit achievable using items idx to n-1 with capacity weight*/
class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return helper(0, W, val, wt, dp);
    }
    int helper(int idx, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (idx == val.size() || capacity == 0)
            return 0;
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];
        if (wt[idx] <= capacity) {
            int include = val[idx] + helper(idx + 1, capacity - wt[idx], val, wt, dp);
            int exclude = helper(idx + 1, capacity, val, wt, dp);
            return dp[idx][capacity] = max(include, exclude);
        } 
        else {
            return dp[idx][capacity] = helper(idx + 1, capacity, val, wt, dp);
        }
    }
};
