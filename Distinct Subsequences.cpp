class Solution {
public:
    int numDistinct(string s, string t) {
        return countWays(0, 0, s, t);
    }
    int countWays(int i, int j, string& s, string& t) {
        if (j == t.length()) 
            return 1; // successfully matched all of t
        if (i == s.length()) 
            return 0; // s is exhausted, can't match t
        if (s[i] == t[j]) {
            // match OR skip
            return countWays(i + 1, j + 1, s, t) + countWays(i + 1, j, s, t);
        } 
        else {
            // skip s[i]
            return countWays(i + 1, j, s, t);
        }
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // Initialize DP table with -1 (uncomputed state)
        vector<vector<int>> dp(n, vector<int>(m, -1));
      /*row → the index in string s
        column → the index in string t
        dp[i][j] stores the number of distinct subsequences of the substring s[i:] (i.e., s from index i to end) that equals the substring t[j:] (i.e., t from index j to end). */
        return countWays(0, 0, s, t, dp);
    }
    int countWays(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.length()) 
            return 1; // Fully matched t
        if (i == s.length()) 
            return 0; // Ran out of characters in s
        if (dp[i][j] != -1) 
            return dp[i][j]; // Use cached result
        if (s[i] == t[j]) {
            // Include or exclude s[i]
            dp[i][j] = countWays(i + 1, j + 1, s, t, dp) + countWays(i + 1, j, s, t, dp);
        } 
        else {
            // Skip s[i]
            dp[i][j] = countWays(i + 1, j, s, t, dp);
        }
        return dp[i][j];
    }
};
