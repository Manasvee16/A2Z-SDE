class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        if (!root || !x) // Edge case: empty tree or invalid node
            return -1;  
        // Case 1: If x has a right child → return leftmost node in right subtree
        if (x->right) {
            Node* curr = x->right;
            while (curr->left) {
                curr = curr->left;
            }
            return curr->data;  // leftmost in right subtree
        }
        // Case 2: No right child → search from root
        Node* successor = nullptr;
        Node* curr = root;
        while (curr) {
            if (x->data < curr->data) {
                successor = curr;   // possible successor
                curr = curr->left;  // try to find closer one
            } 
            else if (x->data > curr->data) {
                curr = curr->right; // must look right side
            } 
            else {
                break;  // found the node
            }
        }
        return successor ? successor->data : -1; 
        // If successor is found → return its value, Else → -1 (no successor exists)
    }
};
