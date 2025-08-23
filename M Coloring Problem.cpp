class Solution {
public:
    // graph: V x V adjacency matrix (graph[u][v] == 1 if edge u-v exists)
    // m: maximum number of colors available (colors are 1 to m)
    // V: number of vertices (0 to V-1)
    bool graphColoring(vector<vector<int>>& graph, int m, int V) {
        vector<int> color(V, 0); // color[i] = 0 means uncolored; otherwise 1 to m
        return dfs(0, V, m, graph, color);      // try to color vertex 0 to V-1 recursively
    }

    // Check if we can assign color 'c' to vertex 'u' without violating constraints
    bool isSafe(int u, int c, const vector<vector<int>>& graph, const vector<int>& color, int V) {
        for (int v = 0; v < V; v++) {           // scan all vertices to find neighbors of 'u'
            if (graph[u][v] == 1 &&             // if there is an edge u--v
                color[v] == c) {                // and neighbor v already has color 'c'
                return false;                   // then assigning 'c' to u is not safe
            }
        }
        return true;                            // no neighbor conflicts → safe to use color 'c'
    }
    // Try to color vertex 'u', then 'u+1', ... until all vertices are colored
    bool dfs(int u, int V, int m, vector<vector<int>>& graph, vector<int>& color) {
        if (u == V) 
            return true;                // base case: all vertices colored successfully
        for (int c = 1; c <= m; c++) {          // try each color from 1..m
            if (isSafe(u, c, graph, color, V)) {// if color 'c' fits here
                color[u] = c;                   // choose: assign color 'c' to vertex 'u'
                if (dfs(u + 1, V, m, graph, color))
                    return true;                // recurse: if subsequent vertices can be colored, done
                color[u] = 0;                   // backtrack: undo the choice and try next color
            }
        }
        return false;                           // no color could be assigned → backtrack to previous vertex
    }
};
//TC: O(m^V · V)
//SC: O(V²)
