class Solution {
  public:
  Node* flatten(Node* root) {
    if (!root || !root->next) 
        return root;
    root->next = flatten(root->next); //Recursively flatten the rest of the list to the right
    root = merge(root, root->next); //Merge the current column with the already flattened right list
    return root;
}
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* a, Node* b) {
    if (!a) 
        return b;
    if (!b) 
        return a;
    if (a->data < b->data) { //for ascending order
        a->bottom = merge(a->bottom, b);
        return a;
    } 
    else {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}
};
//TCO (N*M)
//SC O(N)
