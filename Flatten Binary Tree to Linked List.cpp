class Solution {
public:
 TreeNode* prev=nullptr; //a class member variable used to track the previously flattened node. It helps us link root->right = prev during the reverse traversal.
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->right); //First, recursively flatten the right subtree. We are doing reverse preorder traversal (Right → Left → Root) instead of Root → Left → Right so that we can build the list from the end.
        flatten(root->left);      
        root->right=prev; //This connects the current node to the already-built portion of the linked list. By going reverse, we always have the "next" node (prev) already processed, so rewiring is easy
        root->left=nullptr;
        prev=root;
    }
};
