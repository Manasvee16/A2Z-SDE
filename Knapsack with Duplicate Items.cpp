class Solution {
  public:
    int helper(int idx, int capacity, vector<int>& val, vector<int>& wt) 
    { /* idx → current item index we are considering (starting from 0).
      capacity → how much space is left in the knapsack.
      val and wt → arrays of item values and weights. */
        // Base case: last item
        if (idx == val.size() - 1) {
            return (capacity / wt[idx]) * val[idx];
        }
        // Do not take the current item
        int notTake = helper(idx + 1, capacity, val, wt);
        // Take the current item (unbounded, so stay at same index)
        int take = 0; //each recursive call works with its own take and notTake
        if (wt[idx] <= capacity) {
            take = val[idx] + helper(idx, capacity - wt[idx], val, wt); //stay at same index
        }
        return max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        return helper(0, capacity, val, wt);
    }
};
//TC O(2^n)
//SC O(capacity)

class Solution {
  public:
    int helper(int idx, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (idx == val.size() - 1) {
            return (capacity / wt[idx]) * val[idx];
        }
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];
        int notTake = helper(idx + 1, capacity, val, wt, dp);
        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + helper(idx, capacity - wt[idx], val, wt, dp);
        }
        return dp[idx][capacity] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        /* Rows = number of items (n)
        Columns = possible capacities (0 to capacity)
        dp[idx][capacity] stores The maximum profit you can get using items from idx to end, when remaining capacity is capacity */
        return helper(0, capacity, val, wt, dp);
    }
};
//TC O(n*capacity)
//SC O(n*capacity)
