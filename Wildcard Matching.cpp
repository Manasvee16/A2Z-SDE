class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
    bool helper(string& s, string& p, int s1, int p1) {
        //Base case: both strings are fully matched
        if (s1 == s.length() && p1 == p.length()) 
            return true;
        // Pattern ends but string remains
        if (p1 == p.length()) 
            return false;
        //If string ends but pattern has remaining characters, all must be '*' to still match
        if (s1 == s.length()) {
            while (p1 < p.length()) {
                if (p[p1] != '*') 
                    return false;
                p1++;
            }
            return true;
        }
        // If characters match OR pattern has '?'
        if (s[s1] == p[p1] || p[p1] == '?') {
            return helper(s, p, s1 + 1, p1 + 1);
        }
        //  If pattern has '*'
        if (p[p1] == '*') {
            // 2 options:
            // 1. '*' matches 0 characters → move pattern forward
            // 2. '*' matches 1+ characters → move string forward
            return helper(s, p, s1, p1 + 1) || helper(s, p, s1 + 1, p1);
        }
        // Characters don't match
        return false;
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
      /*dp[s1][p1] means Whether the suffix s[s1:] matches the suffix p[p1:]
        dp[0][0] = true means The entire string s matches the entire pattern p*/
        return helper(s, p, 0, 0, dp);
    }
    bool helper(string& s, string& p, int s1, int p1, vector<vector<int>>& dp) {
        if (s1 == s.length() && p1 == p.length()) 
           return true;
        if (p1 == p.length()) 
            return false;
        if (s1 == s.length()) {
            // All remaining pattern characters must be '*'
            for (int i = p1; i < p.length(); i++) {
                if (p[i] != '*') 
                    return false;
            }
            return true;
        }
        if (dp[s1][p1] != -1) 
            return dp[s1][p1];
        bool result = false;
        if (s[s1] == p[p1] || p[p1] == '?') {
            result = helper(s, p, s1 + 1, p1 + 1, dp);
        } 
        else if (p[p1] == '*') {
            // Two choices: match 0 characters or 1+
            result = helper(s, p, s1, p1 + 1, dp) || helper(s, p, s1 + 1, p1, dp);
        } 
        else {
            result = false;
        }
        return dp[s1][p1] = result;
    }
};
