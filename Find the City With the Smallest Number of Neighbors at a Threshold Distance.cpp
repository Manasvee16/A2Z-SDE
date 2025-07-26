class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int> (n, INT_MAX/2)); //n x n adjacency matrix 
        vector<int> cities(n);
        for (int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            graph[u][v]=wt;
            graph[v][u]=wt;
        }
        floyd(n, graph); //to compute all-pairs shortest paths.
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (graph[i][j]<=distanceThreshold && i!=j)
                {
                    cities[i]++;
                }
            }
        }
        int idx=0;
        for (int i=0;i<cities.size();i++)
        {
            if (cities[i]<=cities[idx])
            { //Finds the index idx of the city with minimum number of reachable cities. If there is a tie, chooses the city with the larger index.
                idx=i;
            }
        }
        return idx;
    }
    void floyd(int n, vector<vector<int>>& graph)
    {
        for (int i=0;i<n;i++)
        {
            graph[i][i]=0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (graph[j][i] < INT_MAX && graph[i][k] < INT_MAX)
                        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                  }
              }
          }
    }
};
