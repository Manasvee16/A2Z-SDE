class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int p1=0, p2=0;
        return helper(0,0,text1,text2);
    }
    int helper(int p1, int p2, string text1, string text2)
    {
        if (p1==text1.size() || p2==text2.size())
        {
            return 0;
        }
        if (text1[p1]==text2[p2])
        {
            
            return 1+helper(p1+1, p2+1, text1, text2);
        }
        else
        {
            return max(helper(p1, p2+1, text1, text2), helper(p1+1, p2, text1, text2));
        }
        return 0;
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        dp.resize(text1.size()+1, vector<int> (text2.size()+1, -1));
        return helper(dp,0,0,text1,text2);
    }
    int helper(vector<vector<int>>& dp, int p1, int p2, string& text1, string& text2)
    {
        if (p1==text1.size() || p2==text2.size())
        {
            return 0;
        }
        if (dp[p1][p2]!=-1)
        {
            return dp[p1][p2];
        }
        if (text1[p1]==text2[p2])
        {
            return dp[p1][p2]=1+helper(dp, p1+1, p2+1, text1, text2);
        }
        else
        {
            return dp[p1][p2]=max(helper(dp, p1, p2+1, text1, text2), helper(dp, p1+1, p2, text1, text2));
        }
        return 0;
    }
};
