class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char, int> romans;
        romans.insert({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        for (int i=0;i<s.size();i++)
        {
            //these if conditions handle subtracting values like IV,IX etc
            if (i<s.size()-1 && s[i]=='I' && (s[i+1]=='V'|| s[i+1]=='X'))
            {
                int num=romans[s[i+1]]-romans[s[i]];
                ans+=num;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='X' && (s[i+1]=='L'|| s[i+1]=='C'))
            {
                int num=romans[s[i+1]]-romans[s[i]];
                ans+=num;
                i++;
            }
            else if (i<s.size()-1 && s[i]=='C' && (s[i+1]=='D'|| s[i+1]=='M'))
            {
                int num=romans[s[i+1]]-romans[s[i]];
                ans+=num;
                i++;
            }
            else
                ans+=romans[s[i]];
        }
        return ans;
    }
};
