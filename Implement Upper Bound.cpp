class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;  // go right
            } 
            else {
                high = mid; // possible answer, go left to find lower index
            }
        }
        return low; // first index where arr[i] > target
    }
};
