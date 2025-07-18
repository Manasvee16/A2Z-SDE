class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> nodes; // key->elements, value->idx of inorder
        for (int i = 0; i < inorder.size(); i++) {
            nodes[inorder[i]] = i;
        }
        return helper(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder, nodes);
    }
    TreeNode* helper(int poststart, int postend, int instart, int inend, vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& nodes) 
    { //It builds the root, then builds left and right subtrees by slicing the postorder and inorder arrays properly.
        if (poststart > postend || instart > inend)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postend]); //The last element of postorder in the current range is the root of the current subtree.
        int idx = nodes[root->val];
        root->left = helper(poststart, poststart + idx - instart - 1, instart, idx - 1, postorder, inorder, nodes); // idx-instart=left subtree size
        //poststart to poststart + (idx - instart - 1)
        root->right = helper(poststart + idx - instart, postend - 1, idx + 1, inend, postorder, inorder, nodes); //poststart + left_subtree_size to postend - 1 means poststart + (idx - instart) to postend - 1
        //idx + 1 to inend
        return root;
    }
};
/*If you're at helper(poststart, postend, instart, inend):
Root value = postorder[postend]
Index in inorder = idx = nodes[root->val]
Left subtree size = idx - instart
Left Subtree: postorder: poststart to poststart + (idx - instart - 1), inorder: instart to idx - 1
Right Subtree: postorder: poststart + (idx - instart) to postend - 1, inorder: idx + 1 to inend
*/
