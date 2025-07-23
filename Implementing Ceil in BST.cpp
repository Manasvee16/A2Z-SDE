#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// BST Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
// Solution class with ceil logic using in-order traversal
class Solution {
public:
    int ceil(Node* root, int x) {
        vector<int> inorder;
        dfs(root, inorder);  // Get in-order traversal (sorted)
        // Find the first element in the sorted array that is ≥ x
        auto it = lower_bound(inorder.begin(), inorder.end(), x);
        // If no such element exists
        if (it == inorder.end())
            return -1;
        // Otherwise, return that element
        return *it;
    }
    void dfs(Node* node, vector<int>& inorder) {
        if (!node) 
            return;
        dfs(node->left, inorder);
        inorder.push_back(node->data);
        dfs(node->right, inorder);
    }
};
// Helper function to insert nodes in BST
Node* insert(Node* root, int val) {
    if (!root) 
    return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
// Main function to test the ceil logic
int main() {
    // Build the BST
    Node* root = nullptr;
    vector<int> values = {10, 5, 15, 2, 7, 12, 20};
    for (int val : values)
        root = insert(root, val);
    Solution sol;
    int x;
    cout << "Enter a number to find ceil: ";
    cin >> x;
    int result = sol.ceil(root, x);
    if (result == -1)
        cout << "No ceil found for " << x << endl;
    else
        cout << "Ceil of " << x << " is: " << result << endl;
    return 0;
}
