/*Divide the array into halves recursively
Conquer by sorting each half
Combine the sorted halves using the merge process*/
class Solution {
  public:
    // Main mergeSort function that recursively sorts the array
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;  // Find the middle index
            // Recursively sort the left half
            mergeSort(arr, l, mid);
            // Recursively sort the right half
            mergeSort(arr, mid + 1, r);
            // Merge the two sorted halves
            merge(arr, l, mid, r);
        }
    }
    // Helper function to merge two sorted halves
    void merge(vector<int>& arr, int l, int mid, int r) {
        // Sizes of two subarrays to be merged
        int n1 = mid - l + 1;
        int n2 = r - mid;
        // Create temporary arrays
        vector<int> left(n1), right(n2);
        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];
        // Merge the temporary arrays back into arr[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } 
            else {
                arr[k++] = right[j++];
            }
        }
        // Copy any remaining elements of left[], if any
        while (i < n1) {
            arr[k++] = left[i++];
        }
        // Copy any remaining elements of right[], if any
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
};
