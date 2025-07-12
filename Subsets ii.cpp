class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort to group duplicates
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp, 0);
        return ans;
    }
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx) {
        ans.push_back(temp);  // always add the current subset
        for (int i = idx; i < nums.size(); i++) {
            // skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) //we skip only duplicates after the first one
                continue;
            temp.push_back(nums[i]); // choose
            helper(nums, ans, temp, i + 1); // explore
            temp.pop_back(); // backtrack
        }
    }
};
/*
TC: O(2^n × n)
generate up to 2^n subsets
Each subset may take up to O(n) time to copy
SC: O(n)+O(2^n *n)+O(n)
Recursion stack:Max depth = n, So O(n)
Result storage (ans): Stores up to 2^n subsets
Each subset can be up to n long
So: O(2^n × n)
Temporary vector (temp): Max size = n, So O(n)
*/
