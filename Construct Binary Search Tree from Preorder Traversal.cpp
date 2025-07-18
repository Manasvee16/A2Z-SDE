class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0)
            return nullptr;
       return helper(preorder, 0, preorder.size()-1);
      
    }
    TreeNode* helper(vector<int>& preorder, int start, int end)
    { //[start, end] represents the current subtree being built.
        if (start>end)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[start]); //The first element in the current range is always the root of the subtree
       // Find the first element greater than root (start of right subtree)
        int i = start + 1;
        while (i <= end && preorder[i] < preorder[start]) {
            i++;
        }
        root->left=helper(preorder, start+1, i-1);
        root->right=helper(preorder, i, end);
        return root;
    }
};
