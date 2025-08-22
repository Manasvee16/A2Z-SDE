class Solution {
public:
    //number of subarrays with exact sum = goal
    int numSubarraysWithSum(vector<int>& nums, int goal) { 
        // Number of subarrays with sum = goal  = Number of subarrays with sum ≤ goal - Number of subarrays with sum ≤ goal-1
        return atMost(nums, goal) - atMost(nums, goal - 1); //Subtracting them leaves only the subarrays with sum exactly = goal
    }
    //counts subarrays with sum ≤ goal
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)  // No subarray can have sum < 0
            return 0;
        int left = 0;   // Left boundary of the sliding window
        int sum = 0;    // Sum of elements in current window
        int count = 0;  // Number of valid subarrays in current window
        // Expand the window with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // Include current element in sum
            // Shrink window from the left if sum exceeds goal
            while (sum > goal) {
                sum -= nums[left]; // Remove leftmost element
                left++;  // Move left pointer forward
            }
            // All subarrays ending at 'right' and starting from left..right are valid
            count += (right - left + 1);
        }
        return count; // Return number of subarrays with sum ≤ goal
    }
};
//TC O(N)
//SC O(1)
