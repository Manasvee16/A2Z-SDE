class Solution {
    vector<int> ans;  // Stores inorder traversal of the tree
public:
    void recoverTree(TreeNode* root) {
        if (!root)   // If the tree is empty, nothing to recover
            return;
        findInorder(root); // Step 1: Collect inorder traversal of the tree
        vector<int> temp = ans; // Step 2: Copy inorder traversal into a temporary vector
        sort(temp.begin(), temp.end());  // Step 3: Sort the inorder traversal (correct order for BST)
        // Step 4: Find the two mismatched elements
        int num1 = INT_MIN, num2 = INT_MIN;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != temp[i]) {  // mismatch found
                if (num1 == INT_MIN)  // first mismatch
                    num1 = ans[i];
                else                  // second mismatch
                    num2 = ans[i];
            }
        }
        // At this point, num1 and num2 are the two swapped values in the BST.
        // Step 5: BFS traversal to swap num1 and num2 back in the tree
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* frontt = nodes.front();
            nodes.pop();
            // If this node contains one of the swapped values, fix it
            if (frontt->val == num1) {
                frontt->val = num2;
            }
            else if (frontt->val == num2) {
                frontt->val = num1;
            }
            // Push children into queue (continue BFS)
            if (frontt->left)
                nodes.push(frontt->left);
            if (frontt->right)
                nodes.push(frontt->right);
        }
    }
    // Helper function to get inorder traversal of the tree
    void findInorder(TreeNode* root) {
        if (!root)  // Base case: null node
            return;
        findInorder(root->left); // Traverse left subtree
        ans.push_back(root->val);  // Visit current node
        findInorder(root->right); // Traverse right subtree
    }
};
//TC o(nlogn)
//SC O(n)
