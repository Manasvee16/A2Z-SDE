class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1: unvisited, 0 and 1: two colors
        for (int start = 0; start < n; start++) {
            if (color[start] != -1) 
                continue;  // already visited in earlier component
            queue<int> q;
            q.push(start);
            color[start] = 0;  // Assign first color
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        // Not visited, assign opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } 
                    else if (color[neighbor] == color[node]) {
                        // Conflict: same color as current node
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
