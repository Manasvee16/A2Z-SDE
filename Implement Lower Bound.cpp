class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size(); //we search in the half-open interval [low, high). This convention makes it easier to handle edge cases
    while (low < high) 
    { //search interval is [low, high) (half-open) — meaning high is excluded from the valid range. If we used low <= high, we’d risk checking an index beyond the array bounds, especially when returning low
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1; //The current mid cannot be the answer. Nor can anything to the left of it.
        } 
        else {
            high = mid; //mid might still be a valid lower bound. So we don’t discard mid
        }
    }
    return low; //the first index where arr[index] >= target
    }
};
