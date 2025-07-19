class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        set<int> visited;
        vector<vector<int>> ans;
        for (int i = 0; i < edges.size(); i++) { //create graph and connect nodes
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 0; i < V; i++) { //traverse each node
            if (visited.find(i) == visited.end()) { //the nodes which are not visited means they are not a part of the same component because helper marks nodes of the same component as visited
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
