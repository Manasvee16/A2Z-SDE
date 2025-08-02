class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size(); // [low, high)
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return low; // First index with arr[index] >= target
    }
    int findCeil(vector<int>& arr, int x) {
        int index = lowerBound(arr, x);
        if (index == arr.size()) 
            return -1; // No ceil exists
        return index; // Return the ceil 
    }
};
