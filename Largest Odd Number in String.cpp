class Solution {
public:
    string largestOddNumber(string num) {
       string ans="";
       int idx=-1;
       for (int i=num.size()-1;i>=0;i--) // we are starting from the last digit
       {
            if (idx!=-1) //we have already found an odd digit
            {
                ans+=num[i];
            }
            else if ((int)(num[i])%2!=0) //odd digit found
            {
                idx=i;
                ans+=num[i];
            }  
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};
