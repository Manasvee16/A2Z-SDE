class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> nodes;
        int idx=0; //used to insert elements in correct order.
        vector<vector<int>> ans;
        nodes.push(root);
        bool flag = false; //toggles between false (left-to-right) and true (right-to-left)
        while (!nodes.empty()) {
            int sizee = nodes.size(); //number of nodes at current level.
            vector<int> temp(sizee); // store values of the current level.
            for (int i=0;i<sizee;i++) {
                auto frontt = nodes.front();
                nodes.pop();
                if (!flag) {
                 idx=i; //left to right 
                 } 
                else {
                    idx=sizee-i-1; //right to left
                 }
                 if (frontt->left)
                        nodes.push(frontt->left);
                    if (frontt->right)
                        nodes.push(frontt->right);
                temp[idx]=frontt->val;
            }
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};
