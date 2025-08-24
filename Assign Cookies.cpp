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

//DP
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Step 1: Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); 
        int n = g.size();
        int m = s.size();
        // dp[j] will store the best answer we can get when considering cookies up to index j (we compress one dimension of DP to avoid memory limit issues)
        vector<int> dp(m, -1); // Step 2: Create memoization array
        return helper(g, s, n - 1, m - 1, dp); // Step 3: Call the helper recursion starting from the last child and last cookie
    }
    int helper(vector<int>& g, vector<int>& s, int i, int j, vector<int>& dp) {
        // Base case: if no children or no cookies left → no one can be content
        if (i < 0 || j < 0) 
            return 0;
        // Step 1: If we have already solved this subproblem (cookie j considered), just return the stored result to save time
        if (dp[j] != -1) 
            return dp[j];
        // Step 2: If the current cookie can satisfy the current child
        if (s[j] >= g[i]) {
            // Assign this cookie to this child: 1 + solve for the rest (child i-1 and cookie j-1)
            return dp[j] = 1 + helper(g, s, i - 1, j - 1, dp);
        } 
        else {
            // Step 3: Otherwise, this cookie is too small for this child. So, skip this child (move to i-1, keep j same)
            return dp[j] = helper(g, s, i - 1, j, dp);
        }
    }
};
