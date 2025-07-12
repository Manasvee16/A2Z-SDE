class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, target, candidates, 0);
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int>& temp, int target, vector<int>& candidates, int idx) {
        if (idx == candidates.size())
            return;
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target - candidates[idx] >= 0) {
                temp.push_back(candidates[idx]);
                helper(ans, temp, target - candidates[idx], candidates, idx);
                temp.pop_back();
            }
        helper(ans, temp, target, candidates, idx + 1);
    }
};
/* TC: O(2^(target / min(candidates[i])))
The maximum possible depth of recursion = T / minVal
(because in worst case, you subtract smallest element repeatedly)
SC: O(target / min(candidates))
The max depth of the recursion stack
temp stores elements along the recursion path (up to that same depth)
ans is not counted unless stated
*/
