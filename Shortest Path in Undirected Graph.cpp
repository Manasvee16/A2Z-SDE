class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> dist(adj.size(), INT_MAX);
        queue<pair<int, int>> nodes; //node, dist from src
        dist[src] = 0;
        nodes.push({src, 0});
        while (!nodes.empty())
        {
            int node=nodes.front().first;
            int distance=nodes.front().second;
            nodes.pop();
            for (int nbr:adj[node])
            {
                if (dist[nbr]==INT_MAX || dist[nbr]>distance+1)
                  //if nbr is not visited or new distance is smaller
                {
                    nodes.push({nbr, distance+1});
                    dist[nbr]=distance+1;
                }
            }
        }
        for (int i=0;i<dist.size();i++)
        {
            if (dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};
