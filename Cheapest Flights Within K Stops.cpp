class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            int u = flight[0], v = flight[1], wt = flight[2];
            adj[u].push_back({v, wt});
        }
        // Step 2: Queue for BFS — stores {stops, {city, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // 0 stops, src city, 0 cost
        // Step 3: Track minimum cost to reach each city with stops
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        // Step 4: BFS traversal
        while (!q.empty()) {
            auto [stops, data] = q.front();
            q.pop();
            int u = data.first;
            int costSoFar = data.second;
            if (stops > k) 
                continue;
            for (auto [v, wt] : adj[u]) {
                int newCost = costSoFar + wt;
                // We allow better cost or fewer stops
                if (newCost < minCost[v]) {
                    minCost[v] = newCost;
                    q.push({stops + 1, {v, newCost}});
                }
            }
        }
        if (minCost[dst]==INT_MAX)
            return -1;
        return minCost[dst];
    }
};
