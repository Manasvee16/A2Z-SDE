#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> rankArr;
vector<int> sizeArr;
// Initialize Disjoint Set
void DisjointSet(int n) {
    parent.resize(n);
    rankArr.resize(n, 0);
    sizeArr.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}
// Find ultimate parent with path compression
int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}
// unionByRank
void unionByRank(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) 
        return;
    if (rankArr[pu] < rankArr[pv]) {
        parent[pu] = pv;
    }
    else if (rankArr[pu] > rankArr[pv]) {
        parent[pv] = pu;
    }
    else {
        parent[pv] = pu;
        rankArr[pu]++;
    }
}
// unionBySize
void unionBySize(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) 
        return;
    if (sizeArr[pu] < sizeArr[pv]) {
        parent[pu] = pv;
        sizeArr[pv] += sizeArr[pu];
    } 
    else {
        parent[pv] = pu;
        sizeArr[pu] += sizeArr[pv];
    }
}
// find: check if u and v belong to the same set
bool find(int u, int v) {
    return findParent(u) == findParent(v);
}
// Main function to test the operations
int main() {
    DisjointSet(5);  // initialize with 5 elements: 0 to 4
    unionByRank(0, 1);  // merge set containing 0 and 1
    unionBySize(2, 3);  // merge set containing 2 and 3
    cout << (find(0, 1) ? "true" : "false") << endl;  // true
    cout << (find(0, 3) ? "true" : "false") << endl;  // false
    return 0;
}
