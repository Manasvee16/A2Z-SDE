class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    set<vector<pair<int, int>>> shapes; //keeps track of the relative positions of the island cells w.r.t. the base cell (starting point of that island).
    vector<vector<int>> visited;
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n, vector<int> (m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    dfs(grid, i, j, i, j, temp);
                    shapes.insert(temp); //After the DFS finishes for this island, store its shape
                }
            }
        }
        return shapes.size();
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int baserow, int basecol, vector<pair<int, int>>& temp) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 1 || visited[row][col]!=-1)
            return;
        grid[row][col] = 0;
        visited[row][col]=1;
        temp.push_back({row-baserow, col-basecol});
        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dx[i], col + dy[i], baserow, basecol, temp);
        }
    }
};
