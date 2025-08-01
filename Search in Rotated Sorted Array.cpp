class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // Direct match
            if (nums[mid] == target)
                return mid;
            // Check if the left half [start to mid] is sorted
            if (nums[start] <= nums[mid]) {
                // Left half is sorted (which means pivot is NOT in this part)
                if (nums[start] <= target && target < nums[mid]) {
                    // Target lies in sorted left half
                    end = mid - 1;
                } 
                else {
                    // Target is in the right half (may include pivot)
                    start = mid + 1;
                }
            } 
            else {
                // Right half [mid to end] is sorted (which means pivot is NOT in this part)
                if (nums[mid] < target && target <= nums[end]) {
                    // Target lies in sorted right half
                    start = mid + 1;
                } 
                else {
                    // Target is in the left half (may include pivot)
                    end = mid - 1;
                }
            }
        }
        // Target not found
        return -1;
    }
};
