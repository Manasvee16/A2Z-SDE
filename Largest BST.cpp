class Solution {
public:
    bool isBST(Node* root, int minVal, int maxVal) {
        if (!root) 
            return true;
        // If the node violates BST property
        if (root->data <= minVal || root->data >= maxVal) 
            return false;
        // Recursively check left and right subtrees
        return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
    }
    int countNodes(Node* root) {
        if (!root) 
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // Brute Force function to find the size of the largest BST
    int largestBst(Node* root) {
        if (!root) 
            return 0;
        // If the current tree is a BST, return its size
        if (isBST(root, INT_MIN, INT_MAX)) {
            return countNodes(root);
        }
        // Otherwise, check left and right subtrees
        return max(largestBst(root->left), largestBst(root->right));
    }
};
//TC O(n^2)
//SC O(n)
