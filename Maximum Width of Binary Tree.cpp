class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int ans=INT_MIN;
        queue<pair<TreeNode*, int>> nodes; //int (its index if the tree were complete — i.e., left = 2×i+1, right = 2×i+2)
        nodes.push({root, 0});
        while (!nodes.empty()) {
            int first=-1,last=-1; //store the first and last node indices at the current level
            int minidx = nodes.front().second; //the index of the first node in the current level. Used to normalize all indices (i.e., subtract this from all to avoid overflow in deep trees)
            int n=nodes.size();
            for (int i = 0; i < n; i++) {
                auto frontt = nodes.front().first; //current node
                int idx = nodes.front().second - minidx; // normalized index of the current node.
                nodes.pop();
                if (frontt->left)
                    nodes.push({frontt->left, (long long)2 * idx + 1});
                if (frontt->right)
                    nodes.push({frontt->right, (long long)2 * idx + 2});
                if (i==0)
                    first=idx;
                if (i==n-1)
                    last=idx;
                //Record the first and last indices in the level.
            }
             ans=max(ans, last-first+1);
        }
       return ans;
    }
};
