class Solution {
public:
int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
   int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) 
            return 0;
        int mid = low + (high - low) / 2;
        int count = 0;
        // Count in left and right halves
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        // Count cross reverse pairs
     /*For each i in the left half, we want to count how many js in the right half satisfy: nums[i] > 2 * nums[j]
     We use a while loop to move pointer j as long as the condition holds.
For each valid i, the number of valid js is j - (mid + 1)*/
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));  // all such j form reverse pairs with i
        }
        // Merge step
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        // Remaining elements
        while (left <= mid) 
            temp.push_back(nums[left++]);
        while (right <= high) 
            temp.push_back(nums[right++]);
        // Copy back to original array
        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
        return count;
    }
};
/*TC: 
merge sort=O(nlogn)
divides array in logn and merge in n
two pointers=O(n)
SC:
vector=O(n)
recursion=O(logn)
*/
