class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        dfs(root, inorder);
        int i = 0, j = inorder.size() - 1; //two pointer
        while (i < j) 
        {
            int sum = inorder[i] + inorder[j];
            if (sum == k) 
                return true;
            else if (sum < k) //too small sum
                i++;
            else //too large sum
                j--;
        }
        return false;
    }
      void dfs(TreeNode* node, vector<int>& inorder) {
        if (!node) 
            return;
        dfs(node->left, inorder);
        inorder.push_back(node->val);
        dfs(node->right, inorder);
    }
};
