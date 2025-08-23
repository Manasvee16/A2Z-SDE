class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        vector<int> ans;
        // Step 1: Push every element of every array into the min-heap
        for (int i = 0; i < arr.size(); i++) {          // iterate over all K arrays
            for (int j = 0; j < arr[0].size(); j++) {   // iterate over each element in the array
                minheap.push(arr[i][j]);                // insert element into heap
            }
        }
        // Step 2: Pop elements one by one from the heap (in sorted order)
        while (!minheap.empty()) {               // until heap becomes empty
            ans.push_back(minheap.top());        // take the smallest element from heap
            minheap.pop();                       // remove it from heap
        }
        // Step 3: Return the fully merged + sorted array
        return ans;
    }
};
//TC O(k^2 logk)
//SC O(k^2)
