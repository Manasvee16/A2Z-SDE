class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        helper(s, 0, temp, ans);
        return ans;
    }
    void helper(string& s, int idx, vector<string>& temp, vector<vector<string>>& ans)
    {
        if (idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx ; i<s.length() ; i++)
        { //This tries to divide the string at all possible points
            if(palindrome(idx,i,s))
            { //if the substring s[idx to i] is a palindrome
                temp.push_back(s.substr(idx,i-idx+1)); //position, length
                helper(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    bool palindrome(int st, int ed, string& s)
    {
        while (st<=ed)
        {
            if (s[st]!=s[ed])
            {
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
};
/*
TC: O(2^n * n)
up to 2^n partitions
Each partition can have up to n substrings
SC:	2 O(n)
O(n) recursion depth + O(n) temp storage per call
*/
