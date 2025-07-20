class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                ans += to_string(curr->val) + ',';
                q.push(curr->left);
                q.push(curr->right);
            } 
            else {
                ans += "null,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) 
            return nullptr;
        vector<string> nodes; //will store all values
        string temp; //helps build each token as we loop through the string.
        // Iterate over each character in the input string `data`
for (char ch : data) {
    // If the character is a comma, that means we've completed one value
    if (ch == ',') {
        nodes.push_back(temp); // Add the complete value to the nodes list
        temp.clear(); // Clear the temporary string to start collecting the next value
    } else {
        temp += ch;  // Otherwise, keep building the value 
    }
}
       TreeNode* root = new TreeNode(stoi(nodes[0])); // Create the root node of the tree using the first value from the list
queue<TreeNode*> q; // Create a queue for (BFS) to reconstruct the tree
q.push(root); // Start by pushing the root into the queue
int i = 1; // i points to the current index in the 'nodes' vector (we've already used index 0 for the root)
while (!q.empty() && i < nodes.size()) {
    TreeNode* curr = q.front(); // Get the current node whose children we are going to assign
    q.pop();
    if (nodes[i] != "null") { // If the next value is not "null", create a left child
  curr->left = new TreeNode(stoi(nodes[i]));
        q.push(curr->left); 
    }
    i++; // Move to the next index in the list
    if (i < nodes.size() && nodes[i] != "null") { // If we haven’t finished the list and the next value isn't "null", create right child
        curr->right = new TreeNode(stoi(nodes[i]));
        q.push(curr->right);
    }
    i++;
}
return root;
    }
};
/*Each "null" is skipped and not added to the tree.
No dereferencing or object creation is attempted for nulls, so it won’t crash.
The condition i < nodes.size() ensures we never access out-of-bound elements.
The queue becomes empty naturally once all real (non-null) nodes are processed.*/
