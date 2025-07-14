class Solution {
  public:
    int helper(int idx, int rodLength, vector<int>& price) {
        // Base case: only piece of size 1 left
        if (idx == price.size()-1) //last rod piece, which is of length n
        { //at the last piece, there's nothing smaller to go to, so just fill the remaining rod with this piece if possible.
            return (rodLength / (idx+1)) *price[idx]; // How many full pieces of length idx + 1 can fit inside the remaining rodLength, maximum total value we can get using only this piece repeatedly.
        }
        // Option 1: Do not take current piece size
        int notTake = helper(idx + 1, rodLength, price);
        // Option 2: Take current piece size (if it fits)
        int take = 0;
        int currLength = idx + 1;  // Since price[] is 1-indexed
        if (currLength <= rodLength) { //ensures we don't try to cut a piece longer than the remaining rod
            take = price[idx] + helper(idx, rodLength - currLength, price); // unbounded, stay at idx
        }
        return max(take, notTake);
    }
    int cutRod(vector<int>& price, int n) {
        return helper(0, n, price);
    }
};
//TC O(2^n)
//SC O(n)

class Solution {
  public:
    int helper(int idx, int rodLength, vector<int>& price, vector<vector<int>>& dp) {
        if (idx == price.size() - 1) {
            return (rodLength / (idx + 1)) * price[idx];
        }
        if (dp[idx][rodLength] != -1) 
          return dp[idx][rodLength];
        int notTake = helper(idx + 1, rodLength, price, dp);
        int take = 0;
        int currLength = idx + 1;
        if (currLength <= rodLength) {
            take = price[idx] + helper(idx, rodLength - currLength, price, dp);
        }
        return dp[idx][rodLength] = max(take, notTake);
    }
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
/*row is The current index in the price[] array (i.e., rod piece of length i+1)
column is The remaining rod length we still need to cut
dp[i][j]	The maximum obtainable price by using rod pieces from index i to n-1 to fill rod of length j*/
        return helper(0, n, price, dp);
    }
};
//TC O(n^2)
//SC O(n^2)
