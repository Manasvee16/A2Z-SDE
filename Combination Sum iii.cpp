class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, k, n, 1);
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int>& temp, int k, int target, int start) {
        if (k == 0 && target == 0) { //found a valid combination
            ans.push_back(temp);
            return;
        }
        if (k == 0 || target < 0) 
        //Picked too many numbers but still haven’t hit the sum || overshot the sum
            return;
        for (int i = start; i <= 9; i++) {
          //This loop already explores both: "pick" and "not pick" implicitly for every number from start to 9
            temp.push_back(i); //pick
            helper(ans, temp, k - 1, target - i, i + 1); 
            temp.pop_back(); // backtrack
          //The for-loop already acts like the “not pick” by skipping to the next i
        }
    }
};
