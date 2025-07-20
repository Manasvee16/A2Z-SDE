class Solution {
  public:
    void dfs(Node* node, vector<int>& inorder) {
        if (!node) 
            return;
        dfs(node->left, inorder);
        inorder.push_back(node->data);
        dfs(node->right, inorder);
    }
    int kthLargest(Node *root, int k) {
        vector<int> inorder;
        dfs(root, inorder);  
        int n = inorder.size();
        return inorder[n - k];  // kth largest = (n - k)th in sorted array
    }
};
