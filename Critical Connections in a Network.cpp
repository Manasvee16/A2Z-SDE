//An edge (u, v) is a bridge if removing it increases the number of connected components in the graph — i.e., the graph gets disconnected.
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n); //O(n+2e) space because of undirected
        vector<vector<int>> ans;
        vector<int> insert(n); //insert[i]: Time at which node i was first visited.
        vector<int> low(n); //low[i]: The earliest visited node that can be reached from the subtree rooted at i
        vector<int> visited(n, -1);
        for (int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i=0;i<n;i++)
        {
            if (visited[i]==-1)
                dfs(-1, i, adj, visited, insert, low, 0, ans);
        }
        return ans;
    }
    void dfs(int parent, int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& insert, vector<int>& low, int time, vector<vector<int>>& ans)
    {
        visited[node]=1;
        insert[node]=low[node]=time++; //assigns the current timestamp and then increments time for the next node.
      /*When you first visit a node, You haven’t explored any child or back edge yet.
        So the only node you know you can reach is yourself.
        And since you just discovered this node, its insert[node] is the current time.*/
        for (auto nbr:adj[node])
        {
            if (nbr==parent)
                continue;
            if (visited[nbr]==-1)
            {
                dfs(node, nbr, adj, visited, insert, low, time, ans);
                low[node]=min(low[nbr], low[node]);
              /*low[nbr] tells us how early nbr or its subtree can reach (maybe via back edge).
                low[node] is what we're updating — we want to check if node can also reach that same early node through nbr.
                We're updating low[node] because if nbr can reach an earlier node, then node can too (via nbr).*/
                if (low[nbr]>insert[node])
                { // then edge (node - nbr) is a bridge
                  /*From child nbr, we cannot go back to node or any of its ancestors through a back edge.
                    So, the only path from nbr to the earlier part of the graph is through node.
                    Removing the edge (node — nbr) will disconnect nbr and its subtree from the rest of the graph.*/
                    ans.push_back({nbr,node});
                }
            }
            else
            { //if nbr is already visited and is not the parent So it's a back edge from node to nbr
              //A back edge connects the current node (node) to an ancestor (nbr) in the DFS tree. So, we have found a shortcut from node back to a previously visited node (without going through the parent).
                low[node]=min(low[node], insert[nbr]);
            }
        }
    }
};

//TC O(n+e)
