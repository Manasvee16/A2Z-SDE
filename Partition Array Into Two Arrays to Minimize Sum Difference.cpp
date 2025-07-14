class Solution {
public:
    int totalSum = 0;
    int minDiff = INT_MAX;
    void recurse(vector<int>& nums, int index, int count, int halfSize, int currSum) {
        // Base case: If we've picked half the elements
        if (count == halfSize) {
            int otherSum = totalSum - currSum;
            minDiff = min(minDiff, abs(currSum - otherSum));
            return;
        }
        // If not enough elements left to make a valid selection
        if (index >= nums.size() || count > halfSize)
            return;
        // Pick the current number
        recurse(nums, index + 1, count + 1, halfSize, currSum + nums[index]);
        // Skip the current number
        recurse(nums, index + 1, count, halfSize, currSum);
    }
    int minimumDifference(vector<int>& nums) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int halfSize = n / 2;
        recurse(nums, 0, 0, halfSize, 0);
        return minDiff;
    }
};

