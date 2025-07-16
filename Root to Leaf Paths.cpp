class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, temp, ans);
        return ans;
    }
    void dfs(Node* node, vector<int>& temp, vector<vector<int>>& ans) {
        if (!node)
            return;
        temp.push_back(node->data);
        // If it's a leaf node, save the path
        if (!node->left && !node->right) {
            ans.push_back(temp);
        }
        // Recursion on left and right subtrees
        dfs(node->left, temp, ans);
        dfs(node->right, temp, ans);
        // Backtrack
        temp.pop_back();
    }
};
