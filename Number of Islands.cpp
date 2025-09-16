class Solution {
    // Directions for moving up, right, down, left.  dx, dy represent row and column offsets respectively
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<char>> island(n, vector<char>(m, '0')); // Create a grid of size n x m initialized with '0' (water everywhere initially)
        vector<int> ans; // To store number of islands after each operation
        queue<vector<int>> q; // A queue for BFS traversal
        // Process each operation (turning water into land)
        for (int k = 0; k < operators.size(); k++) {
            int row = operators[k][0]; // row index of land being added
            int col = operators[k][1]; // column index of land being added
            island[row][col] = '1'; // Mark this cell as land ('1')
            int count = 0; // Variable to count islands after this operation
            set<vector<int>> vis; // Set to keep track of visited cells in current BFS
            // Traverse the whole grid to count number of islands
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // If cell is land and not visited yet → start BFS
                    if (island[i][j] == '1' && vis.count({i, j}) == 0) {
                        q.push({i, j}); // Push cell into queue
                        vis.insert({i, j}); // Mark as visited
                        bfs(i, j, island, vis, q); // Run BFS to mark the entire island
                        count++; // Increment island count
                    }
                }
            }
            ans.push_back(count); // After checking all cells, store count of islands
        }
        return ans; // Return result for all operations
    }
    // BFS function to explore an island starting from (curri, currj)
    void bfs(int curri, int currj, vector<vector<char>>& island, set<vector<int>>& vis, queue<vector<int>>& q) {
        int n = island.size();    // number of rows
        int m = island[0].size(); // number of columns
        // Standard BFS
        while (!q.empty()) {
            auto f = q.front(); // current cell
            int curri = f[0];
            int currj = f[1];
            q.pop(); 
            // Explore all 4 neighbors
            for (int k = 0; k < 4; k++) {
                int newi = curri + dx[k]; // new row
                int newj = currj + dy[k]; // new column    
                // Check boundary conditions + unvisited land
                if (newi < n && newi >= 0 && newj < m && newj >= 0 && vis.count({newi, newj}) == 0 && island[newi][newj] == '1') {
                    vis.insert({newi, newj}); // Mark neighbor as visited
                    q.push({newi, newj}); // Push neighbor into queue for BFS
                }
            }
        }
    }
};
