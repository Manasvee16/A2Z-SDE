class BSTIterator {
    int idx=0;
     vector<int> inorder;
public:
    BSTIterator(TreeNode* root) {
       
        dfs(root, inorder);
    }
    int next() {
        return inorder[idx++];
      //Returns the next smallest value from the inorder vector. Post-increments idx, so the next call to next() will return the next value.
    }
    
    bool hasNext() {
        if  (idx<inorder.size())
            return true;
        return false;
    }
    void dfs(TreeNode* root, vector<int>& inorder)
    {
        if (!root)
            return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};
