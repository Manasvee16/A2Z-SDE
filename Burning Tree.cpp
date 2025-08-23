class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parents; // Step 1: Create a mapping from each node to its parent
        findParents(parents, root, nullptr); // fill parent relationships
        int ans = 0;  // final answer = minimum time to burn the whole tree
        bool found = false;
        queue<TreeNode*> nodes; // Step 2: Find the target node inside the tree using BFS
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* frontt = nodes.front();
            nodes.pop();
            // if this is the target node
            if (frontt->val == target->val)
            {
                found = true;
                target = frontt; // update target pointer to actual node in tree
                break;
            }
            // push left and right children into BFS
            if (frontt->left)
            {
                nodes.push(frontt->left);
            }
            if (frontt->right)
            {
                nodes.push(frontt->right);
            }
        }
        if (!found)
        {
            return -1;
        }
        traversal(parents, target, ans);  // Step 4: Perform BFS from target node to simulate burning
        return ans; // return total time
    }
    // BFS traversal to spread fire in all directions
    void traversal(unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* target, int& ans)
    {
        queue<TreeNode*> nodes;
        unordered_set<TreeNode*> visited; // keep track of burned nodes
        nodes.push(target);
        visited.insert(target);
        while (!nodes.empty())
        {
            int size = nodes.size();
            bool burnedNew = false; // flag to check if fire spread this round
            // process all nodes burning at this second
            for (int i = 0; i < size; i++) {
                TreeNode* frontt = nodes.front();
                nodes.pop();
                // Left child
                if (frontt->left && !visited.count(frontt->left))
                {
                    nodes.push(frontt->left);
                    visited.insert(frontt->left);
                    burnedNew = true;
                }
                // Right child
                if (frontt->right && !visited.count(frontt->right))
                {
                    nodes.push(frontt->right);
                    visited.insert(frontt->right);
                    burnedNew = true;
                }
                // Parent
                if (parents[frontt] && !visited.count(parents[frontt]))
                {
                    nodes.push(parents[frontt]);
                    visited.insert(parents[frontt]);
                    burnedNew = true;
                }
            }
            // If in this round new nodes were burned, increment time
            if (burnedNew) 
                ans++;
        }
        return;
    }
    // Utility function: record parent pointers for each node
    void findParents(unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* node, TreeNode* parent)
    {
        if (!node)
            return;
        parents[node] = parent; // set parent mapping
        // recursively assign for left and right child
        findParents(parents, node->left, node);
        findParents(parents, node->right, node);
    }
};
