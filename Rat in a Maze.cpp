class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (maze[0][0] == 0) 
            return ans; // No path from start
        vector<vector<bool>> visited(n, vector<bool>(n, false)); //mark cells already visited in the current path to avoid cycles
        string path = "";
        dfs(0, 0, maze, visited, path, ans);
        sort(ans.begin(), ans.end()); // Lexicographical order
        return ans;
    }
    // Direction vectors: Down, Left, Right, Up
    string dir = "DLRU";
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, -1, 1, 0};
/*D → (+1, 0)
L → (0, -1)
R → (0, +1)
U → (-1, 0)*/
    void dfs(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& ans) {
        int n = maze.size();
        // If destination is reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
          //Try all 4 directions
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            // Check if move is safe
            if (isSafe(newRow, newCol, maze, visited)) 
            { //not out of bounds, not visited, and not blocked
                dfs(newRow, newCol, maze, visited, path + dir[i], ans);
            }
        }
        visited[row][col] = false; // unmark the current cell so other paths can reuse it
    }
    bool isSafe(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
       int n = maze.size();
        return (row >= 0 && col >= 0 && row < n && col < n && !visited[row][col] && maze[row][col] == 1);
    }
};
/*TC:	O(4^(n^2)) 
SC:	O(n^2) (visited + recursion stack)*/
