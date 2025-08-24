class Solution {
public:
    int eggDrop(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1)
            return floors;
        if (eggs == 1)
            return floors;  // must do linear search
        int ans = INT_MAX;
        // Try dropping from each floor
        for (int f = 1; f <= floors; f++) {
            int broken = eggDrop(eggs - 1, f - 1); // egg breaks
            int notBroken = eggDrop(eggs, floors - f); // egg survives
            int worst = 1 + max(broken, notBroken);
            ans = min(ans, worst);
        }
        return ans;
    }
};

class Solution {
public:
    // Memo table: dp[eggs][floors]
    vector<vector<int>> dp;
    int eggDrop(int eggs, int floors) {
        dp.assign(eggs + 1, vector<int>(floors + 1, -1));
        return solve(eggs, floors);
    }
    int solve(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1) 
            return floors; // 0 or 1 floor
        if (eggs == 1) 
            return floors; // With 1 egg, try all floors
        if (dp[eggs][floors] != -1) 
            return dp[eggs][floors];
        int ans = INT_MAX;
        // Try dropping from every floor 1..floors
        for (int x = 1; x <= floors; x++) {
            int breaks = solve(eggs - 1, x - 1); // Egg breaks
            int survives = solve(eggs, floors - x); // Egg survives
            int worst = 1 + max(breaks, survives);
            ans = min(ans, worst);
        }
        return dp[eggs][floors] = ans;
    }
};
