class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    void findUnion(int u, int v) {
        int uP = findParent(u);
        int vP = findParent(v);
        if (uP == vP)
            return;
        int rankOfU = rank[uP];
        int rankOfV = rank[vP];
        if (rankOfU < rankOfV) 
            parent[uP] = vP; // Attach smaller rank tree under bigger
        else if (rankOfU > rankOfV) 
                parent[vP] = uP; // Attach smaller rank tree under bigger
        else { // If equal rank
              parent[vP] = uP; // Arbitrarily attach vP under uP
              rank[uP]++; // Increase rank of the new root
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
};
class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) 
        { 
          return a[2] < b[2]; 
        });
        int maxNode = 0;
        for (auto& e : edges) {
            maxNode = max({maxNode, e[0], e[1]});
        }
        DSU dsu(maxNode + 1); // +1 because 0-based indexing
        int ans = 0; //Stores the total weight of the MST.
        int count = 0; //Counts how many edges are included in the MST.
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (dsu.findParent(u) != dsu.findParent(v)) {
                dsu.findUnion(u, v); //it merges the components of u and v
                ans += wt;
                count++;
                if (count == V - 1) //MST is complete because A spanning tree of a graph with V vertices always has exactly V - 1 edges.
                    break;
            }
        }
        return ans;
    }
};
