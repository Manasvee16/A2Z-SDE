class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return low; // first index where arr[i] > target
    }

    int findFloor(vector<int>& arr, int x) {
        int index = upperBound(arr, x);
        if (index == 0) 
            return -1; // all elements are greater than x, no floor
        return index - 1; // floor is the largest element <= x
      //arr[0 to index-1] ≤ x
      //arr[index] > x
    }
};
