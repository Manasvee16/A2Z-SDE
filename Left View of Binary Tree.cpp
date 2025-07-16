class Solution {
  public:
    vector<int> leftView(Node *root) {
        if (!root)
        return {};
        // code here
        queue<Node*> nodes;
        vector<int> ans; //1st node of each level
        nodes.push(root);
        while (!nodes.empty())
        {
            int len=nodes.size(); //Stores the number of nodes at the current level. This helps us identify the first node in each level.
            for (int i=0;i<len;i++)
            {
                Node* newNode=nodes.front();
                nodes.pop();
                if (i==0) //The first node in each level 
                {
                    ans.push_back(newNode->data);
                }
                if (newNode->left)
                    nodes.push(newNode->left);
                if (newNode->right)
                    nodes.push(newNode->right);
            }
        }
        return ans;
    }
};
