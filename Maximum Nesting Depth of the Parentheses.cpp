class Solution {
public:
    int maxDepth(string s) {
        int maxm=0;
        int count=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                count++;
                maxm=max(maxm, count);
            }
            else if (s[i]==')')
                count--;
        }
        return maxm;
    }
};
