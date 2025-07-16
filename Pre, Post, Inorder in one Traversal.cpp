class Solution {
public:
    vector<vector<int>> allTraversals(Node* root) {
        if (!root) 
            return {};
        stack<pair<Node*, int>> st;
        vector<int> pre, in, post;
        st.push({root, 1});
        while (!st.empty()) {
            auto [node, state] = st.top();
            if (state == 1) {
                // Preorder
                pre.push_back(node->data);
                state++; // Move to state 2
                if (node->left)
                    st.push({node->left, 1});
            }
            else if (state == 2) {
                // Inorder
                in.push_back(node->data);
                state++; // Move to state 3
                if (node->right)
                    st.push({node->right, 1});
            }
            else {
                // Postorder
                post.push_back(node->data);
                st.pop(); // Done with this node
            }
        }
        return {in, pre, post};
    }
};
