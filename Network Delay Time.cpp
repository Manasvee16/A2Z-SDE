class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list: node -> list of (neighbor, weight)
        vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
        for (auto edge : times) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }
        // Distance from source node k to all nodes
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // Visited array to mark processed nodes
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            int u = -1;
            // Find the unvisited node with minimum distance
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            // If the closest node is unreachable
            if (dist[u] == INT_MAX) 
                break;
            visited[u] = true;
            // Relax the edges from node u
            for (auto p : adj[u]) {
                int v = p.first;
                int wt = p.second;
                if (!visited[v] && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Find the maximum time taken to reach any node
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) 
                return -1; // Unreachable node
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
