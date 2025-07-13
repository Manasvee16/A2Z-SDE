//greedy
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count=0;
        int p1=0,p2=0; //p1 is for size, p2 is for greed
        while (p1<s.size() && p2<g.size())
        {
            if (s[p1]>=g[p2])
            {
                count++; //1
                p2++;
            }
                p1++;
        }
        return count;
    }
};

//recursion
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); 
        return helper(g, s, g.size() - 1, s.size() - 1);
    }
    int helper(vector<int>& g, vector<int>& s, int i, int j) {
        if (i < 0 || j < 0) 
            return 0;
        if (s[j] >= g[i]) {
            return 1 + helper(g, s, i - 1, j - 1);
        } 
        else {
            return helper(g, s, i - 1, j);
        }
    }
};
