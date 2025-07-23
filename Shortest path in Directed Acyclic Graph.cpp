class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V+1); //Each entry holds {neighbor, weight} pairs.
        queue<pair<int, int>> nodes; //node, wt from src
        vector<int> dist(V, INT_MAX);
        for (auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        dist[0]=0;
        nodes.push({0,0});
        while (!nodes.empty())
        {
            int point=nodes.front().first; 
            int weight=nodes.front().second; 
            nodes.pop();
            for (auto nbr:adj[point])
            {
                int v=nbr.first; 
                int x=nbr.second;
                //v = neighbor node, x = weight of edge point → v
                if (dist[v]>dist[point]+x)
                { //If going through point gives a shorter path to v
                    dist[v]=dist[point]+x; 
                    nodes.push({v, dist[v]});
                }
            }
        }
        return dist;
    }
};
