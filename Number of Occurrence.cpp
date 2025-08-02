class Solution {
public:
    int countFreq(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int first = startpos(nums, start, end, target);
        int last = endpos(nums, start, end, target);
        if (first == -1 || last == -1) 
            return 0; // target not found
        return last - first + 1; // count of target occurrences
    }
    int startpos(vector<int>& nums, int start, int end, int target) {
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) { //We update answer and search further left to ensure it's the first occurrence.
                ans = mid;
                end = mid - 1; // search on the left side
            } 
            else if (nums[mid] < target) { // target must be in right half
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
    int endpos(vector<int>& nums, int start, int end, int target) {
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1; // search on the right side
            } 
            else if (nums[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
