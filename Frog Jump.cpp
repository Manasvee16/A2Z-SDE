class Solution {
public:
    int solve(int idx, vector<int>& height) {
        if (idx == 0) 
            return 0;
        int oneStep = solve(idx - 1, height) + abs(height[idx] - height[idx - 1]);
        int twoStep = INT_MAX;
        if (idx > 1)
            twoStep = solve(idx - 2, height) + abs(height[idx] - height[idx - 2]);
        return min(oneStep, twoStep);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(n - 1, height);
    }
};
//TC O(2^N)
//SC O(N)

class Solution {
public:
    int solve(int idx, vector<int>& height, vector<int>& dp) {
        if (idx == 0) //first stair
            return 0;
        if (dp[idx] != -1) 
            return dp[idx];
        int oneStep = solve(idx - 1, height, dp) + abs(height[idx] - height[idx - 1]);
        int twoStep = INT_MAX;
        if (idx > 1)
            twoStep = solve(idx - 2, height, dp) + abs(height[idx] - height[idx - 2]);
        return dp[idx] = min(oneStep, twoStep);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1); //dp[i] will store the minimum cost to reach stair i
        return solve(n - 1, height, dp);
    }
};
//TC O(N)
//SC O(N)
