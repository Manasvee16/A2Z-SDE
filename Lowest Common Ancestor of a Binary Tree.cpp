class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left=nullptr, *right=nullptr;
        if (!root)
            return root;
        if (root == p || root == q) //we found one of the target nodes.
            return root;
        if (root->left)
            left=lowestCommonAncestor(root->left, p, q);
        if (root->right)
            right=lowestCommonAncestor(root->right, p, q);
        if (left && right) //If both left and right are not null, that means One of p or q is found in the left subtree, The other is found in the right subtree. so, the current root is their lowest common ancestor.
            return root;
        if (left == NULL) //If nothing was found in the left subtree, return the result from the right subtree which could be either q, p, or nullptr
            return right;
        return left; //else return left could be p, q, or nullptr
    }
};
