class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, 0, temp, nums);
        return ans;
    }
    void helper(vector<vector<int>>& ans, int idx, vector<int>& temp, vector<int>& nums)
    {
        if (idx==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(ans, idx+1, temp, nums);
        temp.pop_back();
        helper(ans, idx+1, temp, nums);
    }
};
/*
TC: O(2^n *n)
2^n for recursion, two choices at each step
n for inserting in vector
SC: O(n)
n for recursion call
*/
