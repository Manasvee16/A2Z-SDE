class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); 
        // n = total number of cards
        int totalSum = 0; // will store the sum of all elements
        // Calculate total sum of all cards
        for (int x : cardPoints) 
        {
            totalSum += x;
        }
        // If we take all cards (k == n), return the total sum directly
        if (k == n) 
            return totalSum;
        // Otherwise, instead of directly choosing k cards from ends, we leave behind a continuous subarray of size (n - k).
        // The goal: find the minimum sum subarray of length (n-k), and subtract it from totalSum.
        int windowSize = n - k;  
        int windowSum = 0;
        // Compute the sum of the first window of size (n-k)
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        int minWindowSum = windowSum; // This will store the minimum subarray sum of length (n-k)
        // Slide the window across the array
        for (int i = windowSize; i < n; i++) {
            // Add the new element and remove the oldest element from the window
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            // Update the minimum sum if this window is smaller
            minWindowSum = min(minWindowSum, windowSum);
        }
        // The maximum score = total sum - minimum sum of the (n-k) subarray left behind
        return totalSum - minWindowSum;
    }
};
//TC O(N)
//SC O(1)
