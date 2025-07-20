class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Get all connected components
        vector<vector<int>> components = getComponents(n, edges);
        // Step 2: Create adjacency list for quick edge lookup
        vector<unordered_set<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        int completeCount = 0; // Step 3: Check each component for completeness
        for (auto comp : components) 
        { // For each connected component in the list of components
    bool isComplete = true;  // Assume it's a complete component unless proven otherwise
    int size = comp.size(); // Get the number of nodes in the current component
    for (int i = 0; i < size && isComplete; i++) 
    { // Loop through each node in the component. Continue only if isComplete hasn't been set to false
        for (int j = i + 1; j < size; j++) 
        { // Loop through all nodes after i to check every unique pair (i, j)

            if (adj[comp[i]].find(comp[j]) == adj[comp[i]].end()) 
            { // Check if there is an edge between node comp[i] and comp[j].  adj is an adjacency list in the form of unordered_set for fast lookup
                isComplete = false; // If even one edge is missing, this component is not complete
                break;
            }
        }
    }
    if (isComplete) 
        completeCount++; // If no missing edges were found, increment the count of complete components
}
return completeCount;
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        set<int> visited;
        vector<vector<int>> ans;
        // Create undirected graph
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        // Traverse all nodes to form components
        for (int i = 0; i < V; i++) {
            if (visited.find(i) == visited.end()) {
                helper(i, graph, visited, ans);
            }
        }
        return ans;
    }
    void helper(int start, vector<vector<int>>& graph, set<int>& visited, vector<vector<int>>& ans) {
        vector<int> temp;
        queue<int> traverse;
        visited.insert(start);
        traverse.push(start);
        temp.push_back(start);
        while (!traverse.empty()) {
            int frontt = traverse.front();
            traverse.pop();
            for (int nbr : graph[frontt]) {
                if (visited.find(nbr) == visited.end()) {
                    visited.insert(nbr);
                    traverse.push(nbr);
                    temp.push_back(nbr);
                }
            }
        }
        ans.push_back(temp);
    }
};
