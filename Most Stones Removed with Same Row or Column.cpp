class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<bool>& visited, unordered_map<int, vector<int>>& sameRow, unordered_map<int, vector<int>>& sameCol) 
    {
        visited[node] = true;
        // Explore all nbrs in the same row
        for (int nbr : sameRow[stones[node][0]]) {
            if (!visited[nbr]) {
                dfs(nbr, stones, visited, sameRow, sameCol);
            }
        }
        // Explore all nbrs in the same column
        for (int nbr : sameCol[stones[node][1]]) {
            if (!visited[nbr]) {
                dfs(nbr, stones, visited, sameRow, sameCol);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> sameRow;
        unordered_map<int, vector<int>> sameCol;
        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            int col = stones[i][1];
            sameRow[row].push_back(i);  // store stone index
            sameCol[col].push_back(i);  // store stone index
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, stones, visited, sameRow, sameCol);
            }
        }
        return n - components;
    }
};
