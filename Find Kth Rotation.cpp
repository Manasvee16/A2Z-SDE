class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int n = arr.size();
        while (low <= high) {
            /*If the current subarray is already sorted, then the leftmost element is the smallest.
            This means no rotation or you're looking at the unrotated portion.
            Return low as the index of the minimum element (rotation count).*/
            if (arr[low] <= arr[high]) 
              return low;
          //you're checking whether arr[mid] is less than or equal to both its neighbors, even at the edges of the array.
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n; //ensures the result is always non-negative
            // Check if mid is minimum
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) { //it is the minimum element
                return mid; //that's the rotation count k
            }
            // Go to the unsorted half
            if (arr[mid] >= arr[low]) {
                // left part is sorted, so the pivot is in the right half 
                low = mid + 1;
            } 
            else {
                // right part is sorted, so the pivot is in the left half 
                high = mid - 1;
            }
        }
        return 0; // Should not reach here for valid input
    }
};
