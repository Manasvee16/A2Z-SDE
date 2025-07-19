class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *left, *right;
        if (root->left && p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->right && p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
