//no need to find the entire inorder
class Solution {
    int count=0, ans=0;
public:
int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);  
    return ans; 
}
 void dfs(TreeNode* node, int k) { //inorder traversal
    if (!node) 
        return;
    dfs(node->left, k);
    count++;
if (count==k)
    {
        ans=node->val;
        return;
    }
    dfs(node->right, k);
}
};

class Solution {
public:
int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;
    dfs(root, inorder);  
    return inorder[k - 1]; 
}
 void dfs(TreeNode* node, vector<int>& inorder) {
    if (!node) 
        return;
    dfs(node->left, inorder);
    inorder.push_back(node->val);
    dfs(node->right, inorder);
}
};
