/*After sorting the array, if we want to make all elements from index l to r (i.e., in a window [l, r]) equal to nums[r], we must increase the smaller ones up to nums[r].
if our current window has size w = (r - l + 1), and the target value is nums[r]
We want: each_element_in_window = nums[r]
So, for every element nums[i] from i = l to r, we need to add: (nums[r] - nums[i]) → number of increments for nums[i]
Total = ∑ (nums[r] - nums[i])   for all i from l to r
      = w * nums[r] - (sum of nums[l to r])
 Repeated (r - l + 1) times
 So total = nums[r] * (r - l + 1)*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0, maxFreq = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            // If this window is invalid, shrink it from the left
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};
