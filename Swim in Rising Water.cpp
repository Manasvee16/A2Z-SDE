class Solution {
    // Directions for moving up, right, down, left
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    // Min-heap (priority queue) where: key = maximum height encountered so far, value = {row, col} of the cell
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited array to avoid re-processing cells
         minheap.push({grid[0][0], {0, 0}}); // Start at (0,0) with "time" = grid[0][0] Because initially, you must wait until water reaches height grid[0][0]
        visited[0][0] = 1;
        // Standard Dijkstra loop: always expand the cell with the smallest "time"
        while (!minheap.empty())
        {
            int topp = minheap.top().first;              // Current water level required
            int row  = minheap.top().second.first;       // Current row
            int col  = minheap.top().second.second;      // Current col
            minheap.pop();
            if (row == n-1 && col == m-1)
                return topp; // If we've reached bottom-right corner → answer found 
            else // Otherwise, expand its neighbors
                dfs(row, col, grid, visited, topp);
        }
        return -1; // Should never happen if input is valid
    }
    // Expand neighbors of the current cell
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, int topp) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) { // Explore 4 directions
            int newi = row + dx[i];
            int newj = col + dy[i];
            // Check bounds and if not visited
            if (newi >= 0 && newj >= 0 && newi < n && newj < m && visited[newi][newj] == 0) {
                visited[newi][newj] = 1; // Mark visited
                minheap.push({max(grid[newi][newj], topp), {newi, newj}}); // The cost of moving into this neighbor is: max(currentWaterLevel, grid[newi][newj]) Because you may need to wait until water rises enough to enter.
            }
        }
        return;
    }
};
