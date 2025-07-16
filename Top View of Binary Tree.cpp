class Solution {
  public:
    vector<int> topView(Node *root) {
        if (!root)
            return {};
        map<int, int> nodes; //axis, node_data It's sorted by keys, so when we iterate over it later, values come from left to right.
        vector<int> ans;
        queue<pair<Node*, int>> q; //the current node, its horizontal distance (hd) from the root
        q.push({root, 0});
        while (!q.empty()) {
            auto front=q.front();
            q.pop();
            Node* curr=front.first;
            int hd=front.second;
            if (nodes.find(hd)==nodes.end()) 
            { //only the first node seen from the top (smallest depth at that hd) is stored.
                nodes[hd]=curr->data;
            }
            if (curr->left)
                q.push({curr->left, hd - 1});
            if (curr->right)
                q.push({curr->right, hd + 1});
        }
        for (auto entry:nodes) {
            ans.push_back(entry.second);
        }
        return ans;
    }
};
