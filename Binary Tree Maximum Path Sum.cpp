class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
    int dfs(TreeNode* node, int& sum) 
    { //sum by reference to update the global max as it recurses.
        if (!node)
            return 0;
        //If the returned value is negative, we take 0 instead — because including a negative path would only reduce the sum.
        int leftsum = max(dfs(node->left, sum), 0);
        int rightsum = max(dfs(node->right, sum), 0);
        int newsum = max(leftsum, rightsum) + node->val; //This value will be returned to the parent to extend the path.
        sum = max(sum, leftsum + rightsum + node->val); //a path that Starts from the left child, goes up to the current node, and then goes down to the right child. That path's total sum is this. This path goes through the current node and connects both subtrees. It is a complete path (but can't be extended further upwards).
        return newsum; //We can only extend the path in one direction (either left or right) upward. If we include both left and right, the path becomes a Y-shape, and we can't pass that to parent (parent can't accept both arms)
    }
};
