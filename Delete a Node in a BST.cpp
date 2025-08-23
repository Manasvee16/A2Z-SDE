class Solution {
    vector<int> ans;       // Stores inorder traversal values of the BST
    bool found=false;      // Flag to check if the key to delete exists in the tree
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)                 // If tree is empty, just return
            return root;
        findInorder(root, key);    // Perform inorder traversal & store values in `ans` Also check if key exists in tree
        if (found==false)          // If key is not found, return the original tree
            return root;
        ans.erase(remove(ans.begin(), ans.end(), key), ans.end());  // Remove the key from the inorder list
        return buildTree(ans, 0, ans.size()-1); // Rebuild the BST from the modified inorder list
    }
    // Helper function: Perform inorder traversal (Left → Root → Right)
    void findInorder(TreeNode* root, int key)
    {
        if (!root)                 // Base case: reached null node
            return;
        findInorder(root->left, key);   // Visit left subtree
        ans.push_back(root->val);       // Store current node’s value
        if (root->val==key)             // If current node matches key, mark it as found
            found=true;
        findInorder(root->right, key);  // Visit right subtree
    }
    // Helper function: Build a balanced BST from a sorted inorder list
    TreeNode* buildTree(vector<int>& ans, int start, int end)
    {
        if (start>end)                  // Base case: no elements left
            return nullptr;
        int mid=start+(end-start)/2;    // Pick middle element for balance
        TreeNode* root=new TreeNode(ans[mid]); // Create new node
        // Recursively build left and right subtrees
        root->left=buildTree(ans, start, mid-1);
        root->right=buildTree(ans, mid+1, end);
        return root;                    // Return constructed subtree
    }
};
