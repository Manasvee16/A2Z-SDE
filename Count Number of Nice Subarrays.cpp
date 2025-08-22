class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, odd = 0;  
        // left: start of window
        // right: end of window
        // odd: count of odd numbers in current window
        int count = 0; // Total number of nice subarrays found
        // Expand window by moving 'right' pointer
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0)
                odd++;  
            // If current element is odd, increment odd count
            // Shrink window from left if odd count exceeds k
            while (odd > k) {
                if (nums[left] % 2 != 0)
                    odd--;  // Decrease odd count as we remove left element
                left++;     // Move left pointer forward
            }
            // If odd count equals k, count all valid subarrays ending at 'right'
            if (odd == k) {
                int temp = left;
                // Use temp to count all subarrays starting from left..right with exactly k odd numbers
                while (odd == k) {
                    count++;  
                    // Count current subarray
                    if (nums[temp] % 2 != 0)
                        odd--;  // Removing an odd number reduces odd count
                    temp++;     // Move start forward for next subarray
                }
                // Restore odd count for main window
                odd++;  
            }
        }
        return count;  
        // Return total number of subarrays with exactly k odd numbers
    }
};
//TC O(N^2)
//SC O(1)
