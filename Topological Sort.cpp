//DFS
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> topoOrder;
    vector<bool> visited;
    vector<bool> inRecStack;
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build the graph
        graph.clear();
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]); // directed edge: u → v
        }
        // Step 2: Initialize visited arrays
        visited.assign(V, false);
        inRecStack.assign(V, false);
        topoOrder.clear();
        // Step 3: DFS on all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i)) {
                    return {}; // return empty if a cycle is found
                }
            }
        }
        // Step 4: Reverse to get correct topological sort
        reverse(topoOrder.begin(), topoOrder.end());
        return topoOrder;
    }
    bool dfs(int node) {
        visited[node] = true;
        inRecStack[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor)) return true;
            } 
            else if (inRecStack[neighbor]) {
                return true; // cycle detected
            }
        }
        inRecStack[node] = false;
        topoOrder.push_back(node); // add after visiting all children
        return false;
    }
};

//BFS
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> topoOrder;
        queue<int> nodes;
        vector<int> indegree(V, 0);
        for (auto i:edges)
        {
            graph[i[0]].push_back(i[1]); // add directed edge u → v in adjacency list
            indegree[i[1]]++;
        }
        for (int i=0;i<V;i++)
        {
            if (indegree[i]==0)
                nodes.push(i);
        }
        while (!nodes.empty())
        {
            int frontt=nodes.front();
            nodes.pop();
            topoOrder.push_back(frontt);
            for (int neighbor:graph[frontt])
            {
                indegree[neighbor]--; // remove the current edge
                if (indegree[neighbor]==0)
                    nodes.push(neighbor);
            }
        }
        return topoOrder;
    }
};
