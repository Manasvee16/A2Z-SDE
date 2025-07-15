class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        vector<int> ans;
        vector<int> curr;
        helper(arr, 0, -1, ans, curr);
        return ans;
        
    }
    void helper(vector<int>& arr, int idx, int previdx, vector<int>& ans, vector<int>& curr)
    {
        if (idx==arr.size())
        {
            if (curr.size()>ans.size())
                ans=curr;
            return;
        }
        if (previdx==-1 || arr[idx]>arr[previdx])
        {
            curr.push_back(arr[idx]);
            helper(arr, idx+1, idx, ans, curr);
            curr.pop_back();
        }
        helper(arr, idx+1, previdx, ans, curr);
        
    }
};
