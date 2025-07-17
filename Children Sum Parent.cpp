class Solution {
public:
    int isSumProperty(Node *root) {
        if (!root || (!root->left && !root->right))
            return 1; // Leaf or null node always satisfies the property
        int left_val = 0, right_val = 0;
        if (root->left)
            left_val = root->left->data;
        if (root->right)
            right_val = root->right->data;
        if ((root->data == left_val + right_val) && isSumProperty(root->left) && isSumProperty(root->right)) {
            return 1;
        }
        return 0;
    }
};
