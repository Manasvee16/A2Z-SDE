class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<int> temp;
        vector<vector<int>> ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int sizee = nodes.size();
            while (sizee--) {
                auto frontt = nodes.front();
                nodes.pop();
                temp.push_back(frontt->val);
                if (frontt->left)
                    nodes.push(frontt->left);
                if (frontt->right)
                    nodes.push(frontt->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
