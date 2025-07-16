/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> nodes;  //stores current node, horizontal distance from root, level from root
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> traverse; //multiset stores in sorted order
        //x=vertical order, y=depth
        nodes.push({root, {0,0}});
        while (!nodes.empty())
        {
            auto frontt=nodes.front().first;
            auto [x,y]=nodes.front().second;
              nodes.pop();
            traverse[x][y].insert(frontt->val);
            if (frontt->left)
                nodes.push({frontt->left, {x-1, y+1}});
            if (frontt->right)
                nodes.push({frontt->right, {x+1, y+1}});
        }
        for (auto i:traverse) //For each vertical column x
        {
             vector<int> temp;
            for (auto j:i.second) //For each depth y in vertical x
            {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp); //Push the full vertical column
        }
        return ans;
    }
};
