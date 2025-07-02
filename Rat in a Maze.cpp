#include <bits/stdc++.h>

using namespace std;
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
     void helper(vector<vector<int> > &grid, int row, int col, vector<vector<int> > &visited, string path, vector<string> ans)
    {
        if (row==grid.size()-1 || col==grid[0].size()-1)
        {
            ans.push_back(path);
            return;
        }
     for (int i=0;i<4;i++)
    {
        int newi=row+dx[i];
        int newj=col+dy[i];
        if (newi>=0 && newi<grid.size() && newj>=0 && newj<grid[0].size() && visited[newi][newj]==0 &&  grid[newi][newj]==1)
        {
            if (dx[i]==1)
            path+='R';
            if (dx[i]==-1)
            path+='L';
            if (dy[i]==1)
            path+='U';
            if(dy[i]==-1)
            path+='D';
            visited[row][col]=1;
            helper(grid, newi, newj, visited, path, ans);
            visited[row][col]=0;
        }
    }
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        if (grid[0][0]==0)
            return {"-1"};
        vector<vector<int> > visited(0);
        string path="";
        vector<string> ans;
       helper(grid, 0, 0, visited, path, ans);
        return ans;
    }
   
int main() {
    vector<vector<int>> grid = { {1, 0, 0, 0} , {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<string> ans1=findPath(grid);
    for (auto i:ans1)
    {
    cout<<i<<" ";
    }
    return 0;

}
