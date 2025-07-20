class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        // Loop over each window starting index
        for (int i = 0; i <= arr.size() - k; i++) 
        {
            set<int> windowSet;  // Will store distinct elements
            // Traverse the current window of size k
            for (int j = i; j < i + k; j++) 
            {
                windowSet.insert(arr[j]); // Automatically removes duplicates
            }
            result.push_back(windowSet.size());  // Count of distinct elements
        }
        return result;
    }
};
