class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // Map each node pointer to its parent pointer so we can move upward during BFS.
        findParents(parent, root, nullptr); // Fill the parent map with a DFS (or BFS) starting at root.
        vector<int> ans;  // We’ll collect all node values exactly k edges away from target here.
        bfsFromTarget(parent, target, k, ans); // Run a BFS starting from target, walking to left, right, and parent.
        return ans; // Return the collected values.
    }
    // Build parent links: parent[cur] = par for every node in the tree.
    void findParents(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* cur, TreeNode* par)
    {
        if (!cur) 
            return;                    // Base case: nothing to do for null nodes.
        parent[cur] = par;                   // Record the parent of the current node.
        findParents(parent, cur->left, cur); // Recurse to the left subtree; current is parent.
        findParents(parent, cur->right, cur);// Recurse to the right subtree; current is parent.
    }
    // Level-order BFS starting at 'start' (the target), stopping at distance 'k'.
    void bfsFromTarget(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* start, int k, vector<int>& out)
    {
        queue<TreeNode*> q;              // Standard queue for BFS.
        unordered_set<TreeNode*> seen;   // Prevents revisiting nodes (avoids cycles via parent links).
        q.push(start);                   // Begin from the target node.
        seen.insert(start);              // Mark target as visited.
        int dist = 0;                    // Distance from target (level number).
        while (!q.empty()) {             // BFS over layers.
            int sz = q.size();           // Number of nodes at the current distance 'dist'.
            if (dist == k) {             // If we reached the required distance,
                // collect all nodes currently in the queue (they’re all exactly k away).
                while (!q.empty()) {
                    out.push_back(q.front()->val);
                    q.pop();
                }
                return;                  // Done.
            }
            // Expand one full layer: move to all neighbors (left, right, parent).
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // Neighbor 1: left child
                if (node->left && !seen.count(node->left)) {
                    seen.insert(node->left);
                    q.push(node->left);
                }
                // Neighbor 2: right child
                if (node->right && !seen.count(node->right)) {
                    seen.insert(node->right);
                    q.push(node->right);
                }
                // Neighbor 3: parent
                TreeNode* p = parent[node];
                if (p && !seen.count(p)) {
                    seen.insert(p);
                    q.push(p);
                }
            }
            ++dist;                       // Finished current layer → go to the next distance.
        }
        // If we exit the loop without returning, there were no nodes at distance k.
    }
};
