class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size(); 
        // Outer loop to control the number of passes
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;  // Track whether any swaps happened in this pass
            // Inner loop to perform comparisons and swaps
            // The last i elements are already sorted, so we go up to n - i - 1
            for (int j = 0; j < n - i - 1; j++) {
                // Compare adjacent elements
                if (arr[j] > arr[j + 1]) {
                    // If they are in the wrong order, swap them
                    swap(arr[j], arr[j + 1]);
                    swapped = true;  // Mark that a swap has occurred
                }
            }
            // If no swaps happened in the inner loop,
            // the array is already sorted, so we can stop early
            if (!swapped) {
                break;
            }
        }
    }
};
