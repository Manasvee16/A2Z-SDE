class Solution {
  public:
    // Wrapper function called by GFG test cases
    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
    // Function to merge two halves and count inversions
    long long merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        long long inv_count = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } 
            else {
                temp.push_back(nums[j++]);
                inv_count += (mid - i + 1);  // Elements remaining in left half are all greater
            }
        }
        while (i <= mid) 
        {
            temp.push_back(nums[i++]);
        }
        while (j <= right) 
        {    
            temp.push_back(nums[j++]);
        }
        for (int k = 0; k < temp.size(); k++)
        {
            nums[left + k] = temp[k];
        }
        return inv_count;
    }
    // Recursive function to apply merge sort and count inversions
    long long mergeSort(vector<int>& nums, int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            inv_count += mergeSort(nums, left, mid);
            inv_count += mergeSort(nums, mid + 1, right);
            inv_count += merge(nums, left, mid, right);
        }
        return inv_count;
    }
};
