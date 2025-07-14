int helper(string& s, int i, int j) {
    if (i > j) 
        return 0; // Empty substring
    if (i == j) 
        return 1; // Single character is always a palindrome
    if (s[i] == s[j]) {
        return 2 + helper(s, i + 1, j - 1); // Palindromic ends
    } 
    else {
        return max(helper(s, i + 1, j), helper(s, i, j - 1)); // Skip one end
    }
}
//TC O(2^n)
//SC O(n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
      /*row is Starting index of the current substring.
        column is Ending index of the current substring.
        dp[i][j] stores the length of the longest palindromic subsequence in the substring s[i to j]*/
        return helper(s, 0, n - 1, dp);
    }
    int helper(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) 
            return 0; // Empty substring
        if (i == j)
             return 1; // Single character is a palindrome
        if (dp[i][j] != -1)            
            return dp[i][j];
        if (s[i] == s[j]) 
        {
            // Include both ends and check inside
            dp[i][j] = 2 + helper(s, i + 1, j - 1, dp);
        } 
        else {
            // Skip one character from either end
            dp[i][j] = max(helper(s, i + 1, j, dp), helper(s, i, j - 1, dp));
        }
        return dp[i][j];
    }
};
//TC O(n^2)
//SC O(n^2)
