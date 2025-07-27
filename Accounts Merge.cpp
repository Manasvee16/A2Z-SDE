class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; //each node is its own parent (initially disjoint)
        }
    }
    void findUnionbySize(int u, int v) {
      //Find ultimate parent (leader/root) of both nodes
        int uP = findParent(u);
        int vP = findParent(v);
        if (uP == vP) //If both already belong to the same set, no need to union.
            return;
        int sizeOfU = size[uP]; //size[] keeps track of how many elements are in the set.
        int sizeOfV = size[vP]; //fetches the size of the component containing v
        if (sizeOfU < sizeOfV) 
        { //attach u under v. This ensures the tree remains balanced and shallow.
            parent[uP] = vP; //merge u's component into v's by making the parent of uP point to vP
            size[vP] += size[uP]; // Update the actual size array
        } 
        else {
            parent[vP] = uP; 
            size[uP] += size[vP];
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
         return parent[node] = findParent(parent[node]); //go up the tree until it reaches the root.
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> names; // email, idx of name
        unordered_map<int, vector<string>> temp; // parent of name, email
        vector<vector<string>> ans; // name, emails
        DSU dsu(accounts.size() + 1); //Each account is treated as a node
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                string name = accounts[i][0];
                if (names.find(email) == names.end()) {
                    names[email] = i;
                } 
                else 
                { //If the email is already mapped, union the current account index with the previously seen index — this means both accounts share an email and should belong to the same group.
                    dsu.findUnionbySize(i, names[email]);
                }
            }
        }
        for (auto i : names) {
          /*You're finding the ultimate parent of the account index i.second.
            Because due to union operations, two different account indices might now belong to the same person, and they will share the same parent in DSU.
            x will be the representative account index for this email.*/
            int x = dsu.findParent(i.second);
            temp[x].push_back(i.first); //emails that belong to the same person.
        }
        for (auto [i, j] : temp) {
            vector<string> store;
            sort(j.begin(), j.end());
            store.push_back(accounts[i][0]); // name of the person for that account index i
            store.insert(store.end(), j.begin(), j.end()); //append all sorted emails from j to the store vector.
            ans.push_back(store);
        }
        return ans;
    }
};
