class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> nodes;
        int count=0;
        nodes.push(root);
        while (!nodes.empty())
        {
            auto frontt=nodes.front();
            nodes.pop();
            if (frontt->left)
                nodes.push(frontt->left);
            if (frontt->right)
                nodes.push(frontt->right);
            count++;
        }
        return count;
    }
};
