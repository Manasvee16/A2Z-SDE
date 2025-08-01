class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> bracs;
        int count=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==')' && bracs.empty())
            {
                count++;
            }
            else if (s[i]=='(')
            {
                bracs.push('(');
            }
            else if (s[i]==')')
            {
                bracs.pop();
            }
        }
        while (!bracs.empty())
        {
            bracs.pop();
            count++;
        }
        return count;
    }
};
