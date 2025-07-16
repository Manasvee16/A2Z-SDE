class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if(!root)
            return {};
        map<int, int> nodes;
      /*store the bottommost node for each horizontal distance (axis):
      Key = horizontal distance from root.
      Value = node data at that horizontal distance.
      The map automatically keeps the horizontal distances in sorted order.*/
        vector<int> ans;
        queue<pair<Node*, int>> traverse; //node, horizontal distance
         traverse.push({root, 0});
        while (!traverse.empty())
        {
            auto frontt=traverse.front().first;
            int axis=traverse.front().second;
            traverse.pop();
            nodes[axis]=frontt->data; //Always overwrite the value at this axis. Because we do a level-order traversal, the last node at each axis will be the bottom view node.
            if (frontt->left)
            {
              traverse.push({frontt->left, axis-1});
            }
            if (frontt->right)
            {
              traverse.push({frontt->right, axis+1});
            } 
        }
        for (auto i:nodes)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
