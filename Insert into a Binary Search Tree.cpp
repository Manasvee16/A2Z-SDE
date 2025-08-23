class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: if the root is null, this means the tree is empty or we have reached a null child where we need to insert the new node.
        if (!root)
        {
            TreeNode* newNode = new TreeNode(val); // create a new node with value = val
            return newNode; // return this node as it becomes part of the tree
        }
        // If the value to insert is smaller than the current node's value
        if (root->val > val)
        {
            // If left child is null, then insert here directly
            if (root->left == nullptr)
            {
                TreeNode* newNode = new TreeNode(val); // create new node
                root->left = newNode; // attach it as left child
                return root; // return root (no structural change at root level)
            }
            insertIntoBST(root->left, val); // Otherwise, recursively call insert into the left subtree
        }
        // If the value to insert is greater than the current node's value
        if (root->val < val)
        {
            // If right child is null, then insert here directly
            if (root->right == nullptr)
            {
                TreeNode* newNode = new TreeNode(val); // create new node
                root->right = newNode; // attach it as right child
                return root; // return root (no structural change at root level)
            }
            insertIntoBST(root->right, val); // Otherwise, recursively call insert into the right subtree
        }
        return root;  // Finally, return the unchanged root pointer
    }
};
