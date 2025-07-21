class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);
        vector<vector<int>> parents(n); // reverse connections to track parents
        // Step 1: Calculate indegree, outdegree, and parent list
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                indegree[v]++;
                parents[v].push_back(u); // u -> v, so u is a parent of v
            }
        }
        // Step 2: Push all terminal nodes (outdegree 0) into queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }
        // Step 3: Process queue using Kahn's algorithm
        vector<bool> safe(n, false);  // mark safe nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (int parent : parents[node]) {
                outdegree[parent]--;
                if (outdegree[parent] == 0)
                    q.push(parent);
            }
        }
        // Step 4: Collect all safe nodes in sorted order
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};
