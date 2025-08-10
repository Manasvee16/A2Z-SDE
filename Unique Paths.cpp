class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=n+m-2; //total number of moves you need to make.
        //If you start at (0,0) and end at (m-1, n-1), you move (m - 1) times down, (n - 1) times right
        int r=m-1; //no. of down moves
        double res=1;
        for (int i=1;i<=r;i++)
        {
            res=res*(N-r+i)/i; //Out of N steps, choose which r=m−1 of them will be the down moves.
        }
        return (int) res;
    }
};
//TC O(M)
//SC O(1)

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    { 
        return countPaths(0, 0, m, n); 
    }
    int countPaths(int i, int j, int m, int n) 
    {
        // Out of bounds
        if (i >= m || j >= n)
            return 0;
        // Destination reached
        if (i == m - 1 && j == n - 1)
            return 1;
        // Move down + Move right
        return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
    }
};
//TC O(2^n+m)
//SC o(m+n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);
    }

    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // Out of bounds
        if (i >= m || j >= n) 
            return 0;
        // Destination reached
        if (i == m - 1 && j == n - 1) 
            return 1;
        if (dp[i][j] != -1) 
            return dp[i][j];
        return dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
    }
};
//TC O(m*n)
//SC O(m*n+m+n)
