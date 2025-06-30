class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, vector<int>& store, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(store);
            return;
        }
        for (int i = ind; i < candidates.size(); ++i) {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue; //skip duplicates
            if (candidates[i] > target)
                break; //early pruning
            store.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], candidates, store, ans);
            store.pop_back(); //backtracking
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // to help skip duplicates efficiently and to enable early termination if a number exceeds the target
        vector<vector<int>> ans;
        vector<int> store; //stores the current path being formed
        solve(0, target, candidates, store, ans);
        return ans;
    }
};
/*
TC: O(2^n × k)
k= average combination length
In worst case: O(2^n) (each number can be chosen or skipped).
With pruning and duplicate skipping, average case is much better.
Sorting: O(n log n).
SC: O(2^n × k)
O(k) recursion stack + O(k) space to store each path + output space.
*/
