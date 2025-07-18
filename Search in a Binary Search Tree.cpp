class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        return helper(root, val);
    }
    TreeNode* helper(TreeNode* node, int val)
    {
        if (!node)
            return nullptr;
        if (node->val==val)
           return node;
        if (node->val>val)
            return helper(node->left, val);
        if (node->val<val)
            return helper(node->right, val);
        return nullptr;
    }
};
