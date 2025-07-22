class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        // Adjacency list: u -> [(v, time)]
        vector<vector<pair<int, int>>> adj(n);
        for (auto road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        // dist[i]: the minimum time (or cost) needed to reach node i from the source node 0
        vector<long long> dist(n, LLONG_MAX);
        // ways[i]: the number of different shortest paths to reach node i from the source node 0
        vector<int> ways(n, 0);
        dist[0] = 0; // time to reach node 0 from node 0 is 0
        ways[0] = 1; // There’s only 1 way to be at node 0 at the beginning, by doing nothing
        vector<bool> visited(n, false);
        for (int count = 0; count < n; count++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            if (u == -1 || dist[u] == LLONG_MAX)
                break;
            visited[u] = true;
            for (auto p : adj[u]) {
                int v = p.first;
                int time = p.second;
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u];
                } 
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
