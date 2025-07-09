class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        // Try every starting point
        for (int i = 0; i < n; i++) {
            // Try every ending point from i to n-1
            for (int j = i; j < n; j++) {
                int sum = 0;
                // Compute sum of subarray arr[i...j]
                for (int l = i; l <= j; l++) {
                    sum += arr[l];
                }
                // If sum matches, update maxLen
                if (sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
//TC O(N^3)
//SC O(1)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        // Build prefix sum array
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        // Try all subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int subSum = 0;
                if (i > 0)
                    subSum = prefix[j] - prefix[i - 1];
                else
                    subSum = prefix[j];
                // If sum equals k, check if it's the longest
                if (subSum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
//TC O(N^2)
//SC O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixMap; // prefixSum -> first index
        int sum = 0; // running prefix sum
        int maxLen = 0; // resul
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // update running sum
            // Case 1: subarray from index 0 to i has sum exactly k
            if (sum == k) {
                maxLen = i + 1;
            }
            // Case 2: check if there's a previous prefix sum (sum - k)
            if (prefixMap.find(sum - k) != prefixMap.end()) {
                int prevIndex = prefixMap[sum - k];
                int len = i - prevIndex;
                maxLen = max(maxLen, len);
            }
            // Case 3: store current prefix sum if it's the first time
            if (prefixMap.find(sum) == prefixMap.end()) {
                prefixMap[sum] = i;
            }
        }
        return maxLen;
    }
};
//TC O(N)
//SC O(N)
