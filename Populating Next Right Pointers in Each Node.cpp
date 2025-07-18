class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            int sizee=nodes.size(); // so we know where each level ends.
            while (sizee--)
            {
                Node* frontt=nodes.front();
                nodes.pop();
                if (frontt->left)
                  nodes.push(frontt->left);
                if (frontt->right)
                  nodes.push(frontt->right);
                if (sizee==0) // last node in the current level
                    frontt->next=nullptr;
                else
                    frontt->next=nodes.front();
            }
        }
        return root;
    }
};
//TC O(N)
//SC O(N)
