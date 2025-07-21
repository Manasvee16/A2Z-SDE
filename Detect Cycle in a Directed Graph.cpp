//BFS
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(V, 0);
        int count=0;
        queue<int> nodes;
        for (auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
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
            count++; 
            for (int nbr:graph[frontt])
            {
                indegree[nbr]--;
                if (indegree[nbr]==0)
                    nodes.push(nbr);
            }
        }
        //If there's a cycle, at least one node will never get its indegree reduced to 0 (since it’s stuck in a circular dependency). So, such nodes will never enter the queue, and hence won’t get added to topoOrder
        return (count!=V);
    }
};

//DFS
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(V, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        // Build the adjacency list
        for (auto i : edges) {
            graph[i[0]].push_back(i[1]);
        }
        // Run DFS for every node
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, graph, visited))
                    return true; // cycle detected
            }
        }
        return false; // no cycle
    }
    bool dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited) {
        visited[node] = 1; // mark as visiting
        for (int nbr : graph[node]) {
            if (visited[nbr] == 1)
                return true; // back edge found -> cycle
            if (visited[nbr] == 0) {
                if (dfs(nbr, graph, visited))
                    return true;
            }
        }
        visited[node] = 2; // mark as visited
        return false;
    }
};
//visiting helps detect cycles in a directed graph during DFS. It means We’ve started processing this node, but haven’t finished it yet because we’re still exploring its downstream neighbors in DFS.
