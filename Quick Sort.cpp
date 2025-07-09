/*Choose a pivot (usually last element)
Partition the array so that:
   All elements less than pivot are on the left
   All elements greater than pivot are on the right
Recursively apply the same logic to subarrays*/
class Solution {
  public:
    // Main QuickSort function
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIndex = partition(arr, low, high);
            // Recursively sort elements before and after partition
            quickSort(arr, low, pivotIndex - 1); // Left of pivot
            quickSort(arr, pivotIndex + 1, high); // Right of pivot
        }
    }
    // Partition function using Lomuto partition scheme
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose last element as pivot
        int i = low - 1; // i tracks index of smaller element
        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // Increment index for smaller element
                swap(arr[i], arr[j]); // Place it before the pivot
            }
        }
        // Place pivot in its correct sorted position
        swap(arr[i + 1], arr[high]);
        return i + 1; // Return pivot index
    }
};
