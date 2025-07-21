class Solution {
  public:
    int floor(Node* root, int x) {
        vector<int> inorder;
        dfs(root, inorder);  
        auto it = lower_bound(inorder.begin(), inorder.end(), x); //find the first element in the sorted array that is ≥ x.
        if (it == inorder.begin() && *it!=x) //If the smallest element is greater than x, then there is no element ≤ x 
            return -1;
        if (it != inorder.end() && *it == x) 
            return x;
        return *(it - 1); //return the previous element
    }
    void dfs(Node* node, vector<int>& inorder) {
        if (!node) 
            return;
        dfs(node->left, inorder);
        inorder.push_back(node->data);
        dfs(node->right, inorder);
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        Node* ptr = root;
        int ans = -1;  // Initialize with -1 to indicate no floor found yet
        while (ptr != nullptr) {
            if (ptr->data == x) {
                // Exact match found; this is the floor
                return ptr->data;
            } 
            else if (ptr->data < x) {
                // Possible floor found; go right to try for a closer one
                ans = ptr->data;
                ptr = ptr->right;
            } 
            else {
                // Current node is too big; go left to find smaller values
                ptr = ptr->left;
            }
        }
        return ans;
    }
};
