class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;  // Window pointers: left and right ends
        int maxm = 0; // Stores the maximum length of valid subarray
        int zeros = 0; // Count of zeros in current window
        // Expand the window by moving 'right' pointer
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)  // If current element is zero
                zeros++; // Increase zero count
            // Shrink window from left if zero count exceeds k
            while (zeros > k) {
                if (nums[left] == 0) // If left element is zero
                    zeros--; // Decrease zero count
                left++; // Move left pointer forward
            }
            // Update maximum length of window satisfying condition
            maxm = max(maxm, right - left + 1);
        }
        return maxm;  // Return the maximum length found
    }
};
//TC O(N)
//SC O(1)
