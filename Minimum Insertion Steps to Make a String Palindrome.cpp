class Solution {
public:
    int minInsertions(string s) 
    { 
        return helper(0, s.size() - 1, s); 
    }
    int helper(int start, int end, string& s) {
        if (start >= end)
            return 0;
        if (s[start] == s[end]) {
            return helper(start + 1, end - 1, s);
        }
        else
        return 1 + (min(helper(start + 1, end, s), helper(start, end - 1, s)));
    }
};

class Solution {
public:
    int minInsertions(string s) { 
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
      /*dp[start][end] stores The minimum no. of insertions needed to make the substring s[start to end] a palindrome.
        row is The starting index of the substring.
        column is The ending index of the substring. */
        return helper(0, n - 1, s, dp); 
    }
    int helper(int start, int end, string& s, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (s[start] == s[end]) {
            dp[start][end] = helper(start + 1, end - 1, s, dp);
        } 
        else {
            dp[start][end] = 1 + min(helper(start + 1, end, s, dp), helper(start, end - 1, s, dp));
        }
        return dp[start][end];
    }
};
//TC O(n^2)
//SC O(n^2)
