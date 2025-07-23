class Solution {
    int dx[8]={0,1,0,-1,1,-1,1,-1};
    int dy[8]={1,0,-1,0,1,-1,-1,1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]!=0) //If the starting cell is blocked, there's no path possible
            return -1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, pair<int, int>>> path; //steps, {x, y}
        vector<vector<int>> visited(n, vector<int> (m, -1));
        path.push({1,{0,0}});
        while (!path.empty())
        {
            int steps=path.front().first; //how far we've come
            int x=path.front().second.first;
            int y=path.front().second.second;
            if (x==n-1 && y==m-1) //we reached the bottom-right corner
                return steps;
            path.pop();
            for (int i=0;i<8;i++)
            {
                int newi=x+dx[i];
                int newj=y+dy[i];
                if (newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==0 && visited[newi][newj]==-1)
                //if New cell is within bounds || Cell is not blocked || Cell is not already visited
                {
                    path.push({steps+1, {newi, newj}});
                    visited[newi][newj]=1;
                }
            }
        }
        return -1; //If we exhaust all possibilities and never reach (n-1,m-1)
    }
};
