class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        if (!root)
            return {};
        vector<int> ans;
        ans.push_back(root->data);
        if (isLeaf(root))
            return ans;
        leftToRight(root, ans);
        addLeaves(root, ans);
        rightToLeft(root, ans);
        return ans;
       
    }
    void leftToRight(Node* root, vector<int>& ans)
    {
        Node* dummy=root->left;
        while (dummy!=nullptr) //worst case o(n)
        {
        if (!isLeaf(dummy))
        { ////Add only non-leaf nodes to avoid duplication of leaf nodes later
            ans.push_back(dummy->data);
        }
          //Prefer left child for boundary, otherwise go right.
        if (dummy->left)
        dummy=dummy->left;
        else
            dummy=dummy->right;
        }
    }
    void rightToLeft(Node* node, vector<int>& ans)
    {
        stack<int> rev;
        Node* dummy=node->right;
        while (dummy!=nullptr) //worst case o(n)
        {
            if (!isLeaf(dummy))
            {
                rev.push(dummy->data);
            }
          //prefer right, else go left. Store non-leaf nodes in stack.
             if (dummy->right)
                dummy=dummy->right;
            else
                dummy=dummy->left;
        }
        while (!rev.empty())
        {
            ans.push_back(rev.top());
            rev.pop();
        }
    }
    void addLeaves(Node* node, vector<int>& ans) //o(2^n), n depends
    {
        if (isLeaf(node))
            ans.push_back(node->data);
        else
        { //Recurse on left and right subtrees to find all leaves.
            if (node->left)
            addLeaves(node->left, ans);
            if (node->right)
            addLeaves(node->right, ans);
        }
    }
    bool isLeaf(Node* node)
    {
        if (!node->left && !node->right)
            return true;
        return false;
    }
};
