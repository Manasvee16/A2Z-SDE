// Custom structure to hold information about each subtree
class abc {
public:
    bool isBST; 
    int min;    // Minimum value in the subtree
    int max;    // Maximum value in the subtree
    int sum;    // Sum of values of the subtree
};
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int result = 0; // Stores the final answer (max sum among BST subtrees)
        helper(root, result); // Call helper to evaluate all subtrees
        return result; // Return the maximum sum found
    }
    // Helper function that traverses the tree in post-order and returns 'abc' struct
    abc helper(TreeNode *root, int &result) {
        // Base case: If the current node is NULL
        if (!root) {
            // An empty tree is considered a valid BST. For correct comparisons, set min to INT_MAX and max to INT_MIN
            return {true, INT_MAX, INT_MIN, 0};
        }
        abc left = helper(root->left, result);
        abc right = helper(root->right, result);
        abc curr; // Create a new 'abc' object to store info about the current subtree        
        curr.sum = left.sum + right.sum + root->val; // Total sum of the current subtree = sum of left + right + current node's value
        curr.min = std::min(root->val, left.min); // Minimum value in the current subtree
        curr.max = std::max(root->val, right.max); // Maximum value in the current subtree
        curr.isBST = left.isBST && right.isBST && (root->val > left.max) && (root->val < right.min); // Check if the current subtree satisfies BST conditions
        if (curr.isBST) { // If it is a valid BST, update the result with the maximum sum found so far
            result = max(result, curr.sum);
        }
        return curr;  // Return the current subtree's information to the parent call
    }
};
