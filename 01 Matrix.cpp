class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    set<pair<int, int>> visited;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        // Step 1: Start BFS from all 0s
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited.insert({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newi = x + dx[i];
                int newj = y + dy[i];
                if (newi < 0 || newj < 0 || newi >= n || newj >= m || visited.find({newi, newj}) != visited.end())
                    continue;
                ans[newi][newj] = 1 + ans[x][y];
                visited.insert({newi, newj});
                q.push({newi, newj});
            }
        }
        return ans;
    }
};
