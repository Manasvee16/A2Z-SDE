//BFS
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

//DFS
class Solution {
public:
    // DFS function to try coloring the graph
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = c;  // Assign the current node with color 'c'
        // Traverse all adjacent neighbors of the current node
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {  
                // If the neighbor has not been visited (uncolored), Assign the opposite color (1 - c) and recurse
                if (!dfs(neighbor, 1 - c, color, graph))
                    return false;  // If any recursive call detects a conflict → not bipartite
            } 
            else if (color[neighbor] == c) {  
                // If the neighbor is already colored with the same color → conflict
                return false;  // Graph is not bipartite
            }
        }
        return true; // If all neighbors are properly colored → this part is bipartite
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();   // Total number of nodes in the graph
        vector<int> color(n, -1); // Keeps track of colors for each node, -1 → unvisited, 0 → first color, 1 → second color
        // Traverse all nodes (to handle disconnected graphs too)
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {   // If this node is not yet visited
                // Start DFS from this node with initial color 0
                if (!dfs(i, 0, color, graph))
                    return false;  // If DFS detects conflict → not bipartite
            }
        }
        return true; // If no conflicts detected → graph is bipartite
    }
};
