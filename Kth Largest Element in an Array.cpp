class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a max heap containing all elements
        // Time: O(n log n) for pushing n elements
        priority_queue<int> maxheap;
        for (int i = 0; i < nums.size(); i++)
            maxheap.push(nums[i]); // Push all n elements → O(n log n)
        // Pop k-1 elements so that the k-th largest is at the top
        // Time: O(k log n)
        for (int i = 0; i < k - 1; i++)
            maxheap.pop();
        // The top now contains the k-th largest element
        // Space: O(n) because we stored all n elements in heap
        return maxheap.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap of size k
        // This will store the k largest elements seen so far
        // Time for building first k: O(k log k)
        priority_queue<int, vector<int>, greater<int>> minheap;

        // Push first k elements
        for (int i = 0; i < k; i++)
            minheap.push(nums[i]); // O(log k) per push

        // Process remaining elements
        for (int i = k; i < nums.size(); i++) {
            // If current number is bigger than smallest in heap
            // Replace the smallest (pop + push)
            if (minheap.top() < nums[i]) {
                minheap.pop();    // O(log k)
                minheap.push(nums[i]); // O(log k)
            }
        }

        // Min heap size never exceeds k → Space: O(k)
        // The top contains the k-th largest element
        // Total Time: O(n log k), better than O(n log n) when k << n
        return minheap.top();
    }
};
