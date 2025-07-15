class Solution {
public:
    int maxLen = 0, totalCount = 0;
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> currSeq;
        helper(nums, 0, currSeq);
        return totalCount;
    }
    void helper(vector<int>& nums, int idx, vector<int>& currSeq) {
        if (idx == nums.size()) {
            if (currSeq.size() > maxLen) {
                maxLen = currSeq.size();
                totalCount = 1;
            } 
            else if (currSeq.size() == maxLen) {
                totalCount++;
            }
            return;
        }
        // Choice 1: take nums[idx] if valid
        if (currSeq.empty() || nums[idx] > currSeq.back()) {
            currSeq.push_back(nums[idx]);
            helper(nums, idx + 1, currSeq);
            currSeq.pop_back();
        }
        // Choice 2: skip nums[idx]
        helper(nums, idx + 1, currSeq);
    }
};

