class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n-1>connections.size())
        { //To connect n nodes, you need at least n-1 edges.
            return -1;
        }
        vector<vector<int>> graph(n);
        vector<int> visited(n, -1);
        for (auto i:connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        int count=0;
        for (int i=0;i<graph.size();i++)
        {
            if (visited[i]==-1)
            {
                dfs(i,graph,visited);
                count++; //Each DFS marks a new component
            }
        }
        return count-1; //To make all count components connected into one, you need count - 1 extra cables. These must be re-used from existing connections.
    }
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited)
    {
        visited[node]=1;
        for (int nbr:graph[node])
        {
            if (visited[nbr]==-1)
                dfs(nbr, graph, visited);
        }
    }
};
