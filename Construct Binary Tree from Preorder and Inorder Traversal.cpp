class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> nodes; // key->elements, value->idx of inorder
        for (int i = 0; i < inorder.size(); i++) {
            nodes[inorder[i]] = i;
        }
        return helper(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, nodes);
    }
    TreeNode* helper(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& nodes) 
    { //It builds the root, then builds left and right subtrees by slicing the preorder and inorder arrays properly.
        if (prestart > preend || instart > inend)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]); //The first element of preorder in the current range is the root of the current subtree.
        int idx = nodes[root->val];
        root->left = helper(prestart + 1, prestart + idx - instart, instart, idx - 1, preorder, inorder, nodes); // idx-instart=left subtree size
        //prestart + 1 to prestart + (idx - instart)
        root->right = helper(prestart + idx - instart + 1, preend, idx + 1, inend, preorder, inorder, nodes); //prestart + left_subtree_size + 1 to preend means prestart + (idx - instart) + 1 to preend
        //idx + 1 to inend
        return root;
    }
};
/*If you're at helper(prestart, preend, instart, inend):
Root value = preorder[prestart]
Index in inorder = idx = nodes[root->val]
Left subtree size = idx - instart
Left Subtree: preorder: prestart + 1 to prestart + (idx - instart) inorder: instart to idx - 1
Right Subtree: preorder: prestart + (idx - instart) + 1 to preend inorder: idx + 1 to inend*/
