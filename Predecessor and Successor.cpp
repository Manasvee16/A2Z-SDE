class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        if (!root)
            return {};
        vector<Node*> inorder; //inorder will give sorted order
        dfs(root, inorder); 
        vector<Node*> ans;
        int n=inorder.size();
        int start=0, end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (inorder[mid]->data==key)
            {
                ans.push_back(inorder[mid-1]); //immediate predecessor
                ans.push_back(inorder[mid+1]); //immediate successor
            }
            if (inorder[mid]->data>key)
            {
                end=mid;
            }
            if (inorder[mid]->data<key)
            {
                start=mid;
            }
        }
        return ans;
    }
    void dfs(Node* node, vector<Node*>& inorder)
    {
        if (node)
        {
        if (node->left)
           dfs(node->left, inorder);
        inorder.push_back(node);
        if (node->right)
           dfs(node->right, inorder);
        }
    }
};
