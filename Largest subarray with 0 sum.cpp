class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();        // size of the array
        int maxLen = 0;            // variable to store maximum length found
        // Fix starting index i
        for (int i = 0; i < n; i++) {
            int sum = 0;           // initialize sum for current subarray starting at i
            // Fix ending index j
            for (int j = i; j < n; j++) {
                sum += arr[j];     // add arr[j] to current sum
                // If subarray [i..j] has sum = 0
                if (sum == 0) {
                    // update maxLen if length (j-i+1) is greater
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;             // return the longest length found
    }
};
// TC = O(N^2) 
// SC = O(1) 

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        // Step 1: Find possible range of prefix sums
        int totalSum = 0, minSum = 0, maxSum = 0;
        for (int x : arr) {
            totalSum += x;          // keep cumulative sum
            minSum = min(minSum, totalSum);  // track minimum prefix sum
            maxSum = max(maxSum, totalSum);  // track maximum prefix sum
        }
        // Step 2: Create an offset to handle negative prefix sums
        int offset = -minSum;       // ensures index >= 0
        int size = maxSum - minSum + 1; // total possible prefix sum range
        // Step 3: Array to store first occurrence of each prefix sum
        // Initialize with -2 (meaning not seen yet)
        vector<int> first(size, -2);
        int prefix = 0, maxLen = 0;
        // Step 4: Special case: prefix=0 means subarray [0..i] is valid
        first[offset] = -1;
        // Step 5: Iterate through the array
        for (int i = 0; i < n; i++) {
            prefix += arr[i];         // update prefix sum
            int idx = prefix + offset;  // map prefix sum to index
            if (first[idx] == -2) {
                // first time seeing this prefix sum
                first[idx] = i;
            } 
            else {
                // prefix already seen -> subarray between them has sum = 0
                maxLen = max(maxLen, i - first[idx]);
            }
        }
        return maxLen;
    }
};
//TC O(nlogn)
//SC O(1)
