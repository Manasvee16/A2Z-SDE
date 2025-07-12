#include <iostream>
#include <vector>
using namespace std;
    int helper(vector<int>& nums, int idx, int currSum, int k) {
        if (idx == nums.size()) {
            // Only count if the subset is non-empty and sum equals k
            if (currSum == k && currSum != 0) 
                return 1;
            else
                return 0;
        }
        // Include current element
        int include = helper(nums, idx + 1, currSum + nums[idx], k);
        // Exclude current element
        int exclude = helper(nums, idx + 1, currSum, k);
        return include + exclude;
    }
    int countSubsequences(vector<int>& nums, int k) {
        return helper(nums, 0, 0, k);
    }
int main() {
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;
    int result = countSubsequences(nums, k);
    cout << result << endl;
    return 0;
}
